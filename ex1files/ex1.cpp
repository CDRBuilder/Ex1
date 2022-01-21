#include "ex1.h"

#include <iostream>

class Expression {
 /////
};

class Value : Expression
{
double value;
public:
Value(double v) {
  value = v;
}
  double Calculate() {
  return this->value;
}
};

/*
class UnaryOperation : Expression {
 protected:
  Expression ex;
};

////////////////////////////////////////////////////Unary

class UPlus : UnaryOperation {
  UPlus(Expression ex) {
    this->ex = ex;
  }
  Expression Calculate() {
    return this->ex.Calculate();
  }
};

class UMinus : UnaryOperation {
  UMinus(Expression ex) {
    this->ex = ex;
  }
  Expression Calculate() {
    return -(this->ex.Calculate());
  }
};

////////////////////////////////////////Binary

class BinaryOperation : Expression {
 protected:
  Expression left, right;
};

class Plus : BinaryOperation {
 public:
  Plus(Expression left, Expression right) {
    this->left = left;
    this->right = right;
  }
  Expression Calculate() {
    return this->left.Calculate() + this->right.Calculate();
  }
};

class Minus : BinaryOperation {
 public:
  Minus(Expression left, Expression right) {
    this->left = left;
    this->right = right;
  }
  Expression Calculate() {
    return this->left.Calculate() - this->right.Calculate();
  }
};

class Mul : BinaryOperation {
 public:
  Mul(Expression left, Expression right) {
    this->left = left;
    this->right = right;
  }
  Expression Calculate() {
    return this->left.Calculate() * this->right.Calculate();
  }
};

class Div : BinaryOperation {
 public:
  Div(Expression left, Expression right) {
    this->left = left;
    this->right = right;
  }
  Expression Calculate() {
    Expression left = this->left.Calculate();
    Expression right = this->right.Calculate();
    try {
      if (right == 0) {
        throw right;
      } else {
        return left / right;
      }
    }
    catch (Expression right) {
      cout << "exception\n";
    }
    return 0;
  }
};

class Variable : Expression {
 public:
  String name;
  Double value;

  Variable(String name, Double value) {
    this->name = name;
    this->value = value;
  }
};
*/
int main() {
/*
  // 1
  try {
    e1 = new Mul(new UMinus(new Value(5.0)), new Plus(new Value(3.5), &(++(*x1))));// -5*(3.5+(++x1))
    cout << "1: " << e1->calculate() << endl; //-37.5
    delete e1;
  } catch (const char *e) {
    if (e1 != nullptr) {
      delete e1;
    }
    std::cout << e << std::endl;
  }*/
Value v = new Value(4);
std::cout << v;
}