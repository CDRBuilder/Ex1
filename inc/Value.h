/*
 * Value.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef VALUE_H_
#define VALUE_H_
#include <iostream>

#include "Expression.h"

class Value: public Expression {
private:
	double* m_value;
public:
	Value(double v);
	virtual ~Value();
	virtual double calculate();
};

#endif /* VALUE_H_ */
