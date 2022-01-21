/*
 * Minus.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#include <iostream>

#include "../inc/Minus.h"


Minus::Minus(Expression* pExLeft, Expression* pExRight)
	: BinaryOperator(pExLeft, pExRight)
{
//	std::cout<<"Minus::Minus()"<<std::endl;

}

Minus::~Minus()
{
//	std::cout<<"Minus::~Minus()"<<std::endl;
}
double Minus::calculate()
{
//	std::cout<<"Minus::Minus()"<<std::endl;
	return left->calculate() - right->calculate();
}



