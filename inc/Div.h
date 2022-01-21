/*
 * Div.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef DIV_H_
#define DIV_H_

#include "BinaryOperator.h"

class Div: public BinaryOperator {
public:
	Div(Expression* pExLeft = nullptr, Expression* pExRight = nullptr);
	virtual ~Div();
	double calculate();
};

#endif /* DIV_H_ */
