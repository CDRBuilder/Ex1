/*
 * Plus.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef PLUS_H_
#define PLUS_H_

#include <iostream>

#include "BinaryOperator.h"

class Plus : public BinaryOperator
{
public:
	Plus(Expression* pExLeft = nullptr, Expression* pExRight = nullptr);
	virtual ~Plus();
	virtual double calculate();
};

#endif /* PLUS_H_ */
