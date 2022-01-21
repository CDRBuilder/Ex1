/*
 * Variable.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include "Expression.h"

class Variable: public Expression {
	std::string name;
	double value;
public:
	Variable(std::string strName, double dblValue);
	Variable(std::string strName, std::string strValue);
	virtual ~Variable();
	virtual double calculate();
	void set(double dblValue) {value = dblValue;}
	void set(std::string strValue) {set(std::stod(strValue));}

	static bool ValidateVarName(std::string& strVarName);

	Variable& operator ++();
	Variable& operator --();
	Variable& operator +=(double dblValue);
	Variable& operator -=(double dblValue);
	Variable& operator ++(int intValue);
	Variable& operator --(int intValue);
};

#endif /* VARIABLE_H_ */
