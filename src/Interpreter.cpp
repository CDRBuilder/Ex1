/*
 * Interpreter.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#include <iostream>
#include <stdexcept>

#include "../inc/ex1.h"

Interpreter::Interpreter() {
	m_Vars.clear();

}

Interpreter::~Interpreter() {
	Variable* v = nullptr;
	while(!m_Vars.empty()) {
		tMapStrVariableIter it = m_Vars.begin();
		v = (*it).second;
		delete v;
		m_Vars.erase(it);
	}
}

void Interpreter::setVariables(std::string strVars)
{
	std::cout<<strVars<<std::endl;
	size_t indexVarBegin = 0;
	size_t indexEQ = 0;
	size_t indexColon  = 0;

	indexColon = strVars.find(';',0);
	if (std::string::npos == indexColon) {
		indexEQ = strVars.find('=', indexVarBegin);
		if(indexEQ == std::string::npos) {
			if(indexColon == 0) {
				// indicates the first search
				throw "illegal variable assignment!";
			}
		} else {
			// '=' was found
			std::string strVarDef = strVars.substr(indexVarBegin, indexEQ- indexVarBegin);
			std::string strVarVal = strVars.substr(indexEQ+1, indexColon-indexEQ);
			std::cout<<__FILE__<<"::"<<__FUNCTION__<<"::"<<__LINE__<<"\t"<<strVarDef<<" = "<<strVarVal<<std::endl;
			std::cout<<"-----------"<<std::endl;

			if (validateVarName(strVarDef) && validateVarVal(strVarVal)) {
				tMapStrVariableIter iter = m_Vars.find(strVarDef);
				if(iter != m_Vars.end()) {
					//variable exists
					(*iter).second->set(strVarVal);
				} else {
					Variable* v = new Variable(strVarDef, std::stod(strVarVal));
					std::pair<std::string, Variable*> mapEntry(strVarDef, v);
					m_Vars.insert(mapEntry);
				}
			} else
				throw "illegal variable assignment!";
		}
	} else {
		setVariables(strVars.substr(0, indexColon));
		setVariables(strVars.substr(indexColon+1));
	}
	
	//}
}

bool Interpreter::validateVarName(std::string varName)
{
	bool bRet = true;
	return bRet;
}

bool Interpreter::validateVarVal(std::string varVal)
{
	bool bRet = true;
	return bRet;
}

void Interpreter::_handleNumber(std::string& strIn, size_t& index)
{
	size_t iNumBegin = index;
	try {
		std::string substr = strIn.substr(iNumBegin, strIn.length() - iNumBegin);
		std::cout<<__FUNCTION__<<" "<<substr<<std::endl;
		std::stod(substr,&index);
		std::cout<<__FUNCTION__<<" Line: "<<__LINE__<<" index = "<<index<<std::endl;
		index += iNumBegin;
	} catch (const std::invalid_argument& ia) {
		throw "Invalid argument";
	}
	std::string tmp = strIn.substr(iNumBegin, index - iNumBegin);
	std::cout<<__FUNCTION__<<" Line: "<<__LINE__<<" tmp = "<<tmp<<std::endl;
	m_outputQ.push(tmp);
	std::cout<<strIn.substr(iNumBegin, index - iNumBegin)<<std::endl;
}

bool Interpreter::_readVariable(std::string& strIn,size_t& index)
{
	bool bRet = true;
	size_t iStartOfVarName = index;
	bool bCont = true;
	while (bCont && strIn.length() > index) {
		char c = strIn.at(index);
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>='0' && c<='9') ) {
			++index;
		} else {
			//character is NOT a valid variable alphabet -> we finished reading the name
			bCont = false;
			if (c == '+' || c == '-' || c== '*' || c== '/' || c== ')') {
				// these are the only tokens that can follow a variable name
				//construct the variable name
				std::string strVarName = strIn.substr(iStartOfVarName, index-iStartOfVarName);
				std::cout<<__FUNCTION__<<" "<<__LINE__<<" Var name: "<<strVarName<<std::endl;
				//verify that the variable is defined
				if (m_Vars.find(strVarName) != m_Vars.end()) {
					// put variable in queue
					m_outputQ.push(strVarName);
				}
			} else {
				bRet = false;
			}
		}
	}
	return bRet;
}

void Interpreter::_Shunting_Yard(std::string strIn)
{
	for (size_t index = 0; index < strIn.length();) {

		char tok = strIn.at(index);
		switch (tok) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
				_handleNumber(strIn, index);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (strIn.at(++index) == '(') {
					if (tok == '-') {
						// special treatment for negation operator
						// for our purposes, '#' replaces '-'
						tok = '#';
					}
					if (tok == '+') {
						tok = '$';
					}
				}
				_handleOperator(tok);
				break;
			case '(':
				m_OperStck.push(tok);
				++index;
				break;
			case ')':
				_handleRightP();
				++index;
				break;
			default:
				_readVariable(strIn,index);
				break;
		}
	}
	while (!m_OperStck.empty()) {
		_MoveStackToQueue();
	}
}

void Interpreter::_MoveStackToQueue()
{
	std::string str(1, m_OperStck.top());
	m_outputQ.push(str);
	m_OperStck.pop();

}

void Interpreter::_handleRightP()
{
	while (!m_OperStck.empty() && m_OperStck.top() != '(') {
		_MoveStackToQueue();
	}
	if (m_OperStck.empty()) {
		throw "mismatched parantheses";
	} else {
		m_OperStck.pop();
	}
}

unsigned char Interpreter::_getPrecedence(char oper)
{
	unsigned char ucRet = 1;
	switch (oper) {
		case '*':
		case '/':
			ucRet = 3;
			break;
		case '+':
		case '-':
			ucRet = 2;
			break;
		case '(':
			ucRet = 5;
			break;
		default:
			break;
	}
	return ucRet;
}

void Interpreter::_handleOperator(char oper)
{
	while (!m_OperStck.empty() && (_getPrecedence(m_OperStck.top()) >= _getPrecedence(oper)) && m_OperStck.top() != '(') {
		_MoveStackToQueue();
	}
	m_OperStck.push(oper);

}

Expression* Interpreter::interpret(std::string strIn)
{
	std::cout<<__FUNCTION__<<" "<<strIn<<std::endl;
	_Shunting_Yard(strIn);

	return _processQueue();
}

Expression* Interpreter::_processQueue()
{
	Expression* expr = nullptr;
	std::stack<Expression*> qOperands;
	while (!m_outputQ.empty()) {
		std::string strOperand = m_outputQ.front();
		std::cout<<__FUNCTION__<<" Line: "<<__LINE__<<" strOperand = "<<strOperand<<std::endl;
		bool bBinaryOperator = false;
		if (isOperator(strOperand, bBinaryOperator)) {
			Expression* pLeft = nullptr;;
			Expression* pRight = nullptr;
			if (bBinaryOperator) {
				std::cout<<__FUNCTION__<<" Line: "<<__LINE__<<"qOperand has "<<qOperands.size()<<" elements"<<std::endl;
				pRight = qOperands.top();
				qOperands.pop();
			}
			if (qOperands.empty()) {
				pLeft = expr;
			} else {
				pLeft = qOperands.top();
				qOperands.pop();
			}
			switch (strOperand.at(0)) {
				case '+':
					expr = new Plus(pLeft, pRight);
					break;
				case '-':
					expr = new Minus(pLeft, pRight);
					break;
				case '*':
					expr = new Mul(pLeft, pRight);
					break;
				case '/':
					expr = new Div(pLeft, pRight);
					break;
				case '#':
					expr = new UMinus(pLeft);
					break;
				case '$':
					expr = new UPlus(pLeft);
					break;
				default:
					break;
			}
			std::cout<<__FILE__<<" "<<__FUNCTION__<<" "<<__LINE__<<" Expr = "<<expr->calculate()<<std::endl;
			if (m_outputQ.size() > 1) {
				//there are still operands, we expect more operators
				//output queue still hasn't popped the operator, so its size is at least 1
				qOperands.push(expr);
			}

		} else {
			double dNumber;
			Expression* pOperand = nullptr;
			if (_isNumber(strOperand, &dNumber)) {
				pOperand = new Value(dNumber);
			} else {
				std::map<std::string, Variable*>::iterator it = m_Vars.find(strOperand);
				if (it != m_Vars.end()) {
					pOperand = it->second;
				}
			}
			qOperands.push(pOperand);
		}
		m_outputQ.pop();
	}

	return expr;
}

bool Interpreter::isOperator(std::string strOperand, bool& bBinaryOperator)
{
	bool bRet = false;
	bBinaryOperator = false;
	switch (strOperand.at(0)) {
		case '+':
		case '-':
		case '*':
		case '/':
			bBinaryOperator = true;
			bRet = true;
			break;
		case '#':
		case '$':
			bBinaryOperator = false;
			bRet = true;
			break;
		default:
			break;
	}
	return bRet;
}

bool Interpreter::_isNumber(std::string strOperand, double* d)
{
	std::cout<<__FUNCTION__<<" Line: "<<__LINE__<<" strOperand = "<<strOperand<<std::endl;
	bool bRet = true;
	try {
		*d = std::stod(strOperand, nullptr);
	} catch (const std::invalid_argument& ia) {
		bRet = false;
	}
	return bRet;
}


