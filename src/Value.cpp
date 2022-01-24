/*
 * Value.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>

#include "../inc/utils.h"
#include "../inc/Value.h"

Value::Value(double v) {
	m_value = new double(v);
	DBGVAR(std::cout, v)<<ENDL;
}

Value::~Value() {
	// TODO Auto-generated destructor stub
	DBGVAR(std::cout, *m_value)<<ENDL;
	if(m_value) {
		delete m_value;
		m_value = nullptr;
	}
}

double Value::calculate()
{
//	std::cout<<"Value::calculate()"<<std::endl;
	return (*m_value);
}

