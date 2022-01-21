/*
 * BinaryOperator.h
 *
 *  Created on: 23 ????? 2019
 *      Author: Yaki
 */

#ifndef BINARYOPERATOR_H_
#define BINARYOPERATOR_H_

#include <iostream>
#include "Expression.h"

class BinaryOperator: public Expression {
protected:
	Expression* left;
	Expression* right;
public:
	BinaryOperator(Expression* pExLeft = nullptr, Expression* pExRight = nullptr){
//		std::cout<<"BinaryOperator()"<<std::endl;
		left = pExLeft;
		right = pExRight;
	}
	virtual ~BinaryOperator() {
//		std::cout<<"Plus::~Plus("<<left->calculate()<<","<<right->calculate()<<")"<<std::endl;
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right=nullptr;
		}
	}

	virtual double calculate()=0;
};

#endif /* BINARYOPERATOR_H_ */
