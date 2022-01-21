/*
 * Minus.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef MINUS_H_
#define MINUS_H_

#include <iostream>

#include "BinaryOperator.h"

class Minus: public BinaryOperator {
public:
	Minus(Expression* pExLeft = nullptr, Expression* pExRight = nullptr);
	virtual ~Minus();
	virtual double calculate();
};

#endif /* MINUS_H_ */
