/*
 * Div.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>

#include "../inc/Div.h"

Div::Div(Expression* pExLeft, Expression* pExRight) : BinaryOperator(pExLeft, pExRight)
{
//	std::cout<<"Div::Div"<<std::endl;
}

Div::~Div()
{
//	std::cout<<"Div::~Div"<<std::endl;
}

double Div::calculate()
{
	if (right->calculate() < 1e-100) {
		throw "division by zero";
	}
	return (left->calculate() / right->calculate());
}




