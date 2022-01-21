/*
 * UMinus.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#include <iostream>
#include "../inc/UMinus.h"


UMinus::UMinus(Expression* pEx) : UnariOperator(pEx)
{
//	std::cout << "UMinus::UMinus" << std::endl;
}

UMinus::~UMinus()
 {
//	std::cout << "UMinus::~UMinus()" << std::endl;
}

double UMinus::calculate()
{
//	std::cout << "UMinus::calculate()" << std::endl;
	return -(m_pEx->calculate());
}





