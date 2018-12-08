#ifndef BINARY_EXPRESSION_H_
#define BINARY_EXPRESSION_H_

#include "expression.h"

struct BinaryExpressionNode : ExpressionNode {
  ExpressionNode *lhs;
  ExpressionNode *rhs;
  
  inline BinaryExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
  }
  inline void Print() override {
    indent();
    cout << "[" << name() << "]\n";
    ii();
    lhs->Print();
    rhs->Print();
    di();
  }
  virtual string name() = 0;
};

#endif