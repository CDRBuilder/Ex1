/*
 * UnariOperator.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#include <iostream>

#include "../inc/UnariOperator.h"


UnariOperator::UnariOperator(Expression* pEx)
{
//	std::cout << "UnariOperator::UnariOperator()" << std::endl;
	m_pEx = pEx;
}

UnariOperator::~UnariOperator()
{
//	std::cout << "UnariOperator::~UnariOperator()" << std::endl;
	if (m_pEx) {
		delete m_pEx;
	}
}




