#ifndef ADDITION_EXPRESSION_H_
#define ADDITION_EXPRESSION_H_

#include "binary_expression.h"

struct AdditionExpressionNode : BinaryExpressionNode {
  
  inline AdditionExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : BinaryExpressionNode(lhs, rhs) {}

  inline string name() override {
    return "Addition";
  }
};

#endif