#ifndef CONDITIONAL_EXPRESSION_H_
#define CONDITIONAL_EXPRESSION_H_

#include "expression.h"

struct ConditionalExpressionNode : ExpressionNode {
  ExpressionNode *cond;
  ExpressionNode *lhs;
  ExpressionNode *rhs;
  
  inline ConditionalExpressionNode(ExpressionNode *cond,
      ExpressionNode *lhs, ExpressionNode *rhs) {
    this->cond = cond;
    this->lhs = lhs;
    this->rhs = rhs;
  }
  inline void Print() override {
  }
};

#endif