/*
 * Value.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>

#include "../inc/ex1.h"
//#include "../inc/Value.h"

Value::Value(double v) {
	m_value = new double(v);
	DBGVARL(std::cout, v);
}

Value::~Value() {
	DBGVARL(std::cout, *m_value);
		if(m_value) {
		delete m_value;
		m_value = nullptr;
	}
}

double Value::calculate()
{
	DBGVARL(std::cout, *m_value);
	return (*m_value);
}

