/*
 * Variable.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>
#include "../inc/Variable.h"


//	Variable();
//	virtual ~Variable();
//	virtual double calculate();
//
//	Variable& operator ++();
//	Variable& operator --();
//	Variable& operator+=(double dblValue);
//	Variable& operator-=(double dblValue);
//	Variable& operator++(int intValue);
//	Variable& operator--(int intValue);

Variable::Variable(std::string strName, double dblValue) {
	name = strName;
	set(dblValue);
}
Variable::Variable(std::string strName, std::string strValue) {
	name = strName;
	set(std::stod(strValue));
}

Variable::~Variable() {
	std::cout<<__FILE__<<"\t"<<__FUNCTION__<<"\t"<<__LINE__<<std::endl;
}

Variable& Variable::operator ++()
{
	value = value + 1;
	return *this;

}

Variable& Variable::operator --()
{
	value = value - 1;
	return *this;

}

Variable& Variable::operator +=(double dblValue)
{
	value = value + dblValue;
	return *this;

}

Variable& Variable::operator -=(double dblValue)
{
	value = value - dblValue;
	return *this;
}

Variable& Variable::operator ++(int intValue)
{
	value = value + 1;
	return *this;

}

Variable& Variable::operator --(int intValue)
{
	value = value - 1;
	return *this;

}

double Variable::calculate()
{
	return value;
}

