/*
 * Interpreter.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <string>
#include <queue>
#include <stack>
#include <map>

class Variable;
class Expression;
typedef std::map<std::string, Variable*> tMapStrVariable;
typedef std::map<std::string, Variable*>::iterator tMapStrVariableIter;
std::ostream& operator<<(std::ostream& os, const tMapStrVariable& obj);

class Interpreter {
	enum Tokens{
		eMINUS = '-',
		ePLUS = '+',
		eMUL = '*',
		eDIV = '/',
		eLPAR = '(',
		eRPAR = ')'
	};

	std::queue<std::string> m_outputQ;
	std::stack<char> m_OperStck;
	tMapStrVariable m_Vars;

	bool validateVarName(std::string varName);
	bool validateVarVal(std::string varVal);
	bool _isNumber(std::string strOperand, double* d);
	bool isOperator(std::string strOperand, bool& bBinaryOperator);
	Expression* _processQueue();
	void _Shunting_Yard(std::string strIn);
	void _handleOperator(char oper);
	unsigned char _getPrecedence(char oper);
	void _handleRightP();
	void _handleNumber(std::string& strIn, size_t& index);
	bool _readVariable(std::string& strIn,size_t& index);
	void _MoveStackToQueue();
public:
	Interpreter();
	virtual ~Interpreter();

	Expression* interpret(std::string strIn);
	void setVariables(std::string strVars);

};

#endif /* INTERPRETER_H_ */
