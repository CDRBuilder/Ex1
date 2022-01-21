/*
 * Value.cpp
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */
#include <iostream>


#include "../inc/Value.h"

Value::Value(double v) {
//	std::cout<<"Value()"<<std::endl;
	m_value = new double(v);
}

Value::~Value() {
	// TODO Auto-generated destructor stub
//	std::cout<<"Value::~Value("<<*m_value<<")"<<std::endl;
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

