/*
 * Plus.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>
#include "../inc/Plus.h"


Plus::Plus(Expression* pExLeft, Expression* pExRight) 	: BinaryOperator(pExLeft, pExRight)
{
//	std::cout<<"Plus::Plus("<<left<<","<<right<<")"<<std::endl;
}

Plus::~Plus()
{
//		std::cout<<"Plus::~Plus("<<left->calculate()<<","<<right->calculate()<<")"<<std::endl;
};

double Plus::calculate()
{
//	std::cout << "Plus::calculate()" << std::endl;
	return left->calculate() + right->calculate();
}


