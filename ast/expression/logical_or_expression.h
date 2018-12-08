#ifndef LOGICAL_OR_EXPRESSION_H_
#define LOGICAL_OR_EXPRESSION_H_

#include "binary_expression.h"

struct LogicalORExpressionNode : BinaryExpressionNode {
  
  inline LogicalORExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : BinaryExpressionNode(lhs, rhs) {}
      
  inline string name() override {
    return "Logical OR";
  }
};

#endif