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

	bool _validateVarName(const std::string& varName);
	bool _validateVarVal(const std::string& varVal);
	bool _isNumber(const std::string& strOperand, double* d);
	bool _isOperator(const std::string& strOperand, bool& bBinaryOperator);
	bool _isDigit(char c) {return (c >= '0' and c <= '9');}
	Expression* _processQueue();
	void _Shunting_Yard(const std::string& strIn);
	void _handleOperator(char oper);
	unsigned char _getPrecedence(char oper);
	void _handleRightP();
	void _handleNumber(const std::string& strIn, size_t& index);
	bool _readVariable(const std::string& strIn,size_t& index);
	void _MoveStackToQueue();
public:
	Interpreter();
	virtual ~Interpreter();
	
	std::string toString() const;

	Expression* interpret(const std::string& strIn);
	void setVariables(const std::string& strVars);

};

#endif /* INTERPRETER_H_ */
