/*
 * UPlus.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#include <iostream>
#include "../inc/UPlus.h"

UPlus::UPlus(Expression* pEx) : UnariOperator(pEx)
{
}

UPlus::~UPlus()
{
//	std::cout << "UPlus::~UPlus(" << m_pEx->calculate() << ")" << std::endl;
}

double UPlus::calculate()
{
	return m_pEx->calculate();
}



