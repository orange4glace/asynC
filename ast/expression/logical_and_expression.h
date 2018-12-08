#ifndef LOGICAL_AND_EXPRESSION_H_
#define LOGICAL_AND_EXPRESSION_H_

#include "binary_expression.h"

struct LogicalANDExpressionNode : BinaryExpressionNode {
  
  inline LogicalANDExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : BinaryExpressionNode(lhs, rhs) {}
      
  inline string name() override {
    return "Logical AND";
  }
};

#endif