/*
 * Mul.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>

#include "../inc/Mul.h"

Mul::Mul(Expression* pExLeft, Expression* pExRight)	: BinaryOperator(pExLeft, pExRight)

{
//	std::cout<<"Mul::Mul()"<<std::endl;

}

Mul::~Mul() {
//	std::cout<<"Mul::~Mul()"<<std::endl;
}

double Mul::calculate()
{
//	std::cout<<"Mul::calculate()"<<std::endl;
	return left->calculate() * right->calculate();
}
