/*
 * UMinus.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef UMINUS_H_
#define UMINUS_H_

#include "iostream"
#include "UnariOperator.h"

class UMinus: public UnariOperator {
public:
	UMinus(Expression* pEx = nullptr);
	virtual ~UMinus();
	virtual double calculate();
};

#endif /* UMINUS_H_ */
