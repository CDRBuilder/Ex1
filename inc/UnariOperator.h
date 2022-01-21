/*
 * UnariOperator.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef UNARIOPERATOR_H_
#define UNARIOPERATOR_H_

#include <iostream>
#include "Expression.h"

class UnariOperator: public Expression {
protected:
	Expression* m_pEx;
public:
	UnariOperator(Expression* pEx = nullptr);
	virtual ~UnariOperator();
	virtual double calculate() = 0;
};

#endif /* UNARIOPERATOR_H_ */
