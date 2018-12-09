#ifndef INCLUSIVE_OR_EXPRESSION_H_
#define INCLUSIVE_OR_EXPRESSION_H_

#include "binary_expression.h"

struct InclusiveORExpressionNode : BinaryExpressionNode {
  
  inline InclusiveORExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : BinaryExpressionNode(lhs, rhs) {}
      
  inline string name() override {
    return "Inclusive OR";
  }

  void Accept(Visitor* visitor) override;
};

#endif