/*
 * Plus.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>
#include "../inc/ex1.h"
#include "../inc/Plus.h"


Plus::Plus(Expression* pExLeft, Expression* pExRight) 	: BinaryOperator(pExLeft, pExRight)
{
	DBGVAR_2L(std::cout, left, right);
}

Plus::~Plus()
{	DBGVAR_2L(std::cout, left->calculate(), right->calculate());
};

double Plus::calculate()
{
//	std::cout << "Plus::calculate()" << std::endl;
	return left->calculate() + right->calculate();
}


