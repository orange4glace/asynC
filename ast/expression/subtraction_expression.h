#ifndef SUBTRACTION_EXPRESSION_H_
#define SUBTRACTION_EXPRESSION_H_

#include "binary_expression.h"

struct SubtractionExpressionNode : BinaryExpressionNode {
  
  inline SubtractionExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : BinaryExpressionNode(SUBTRACTION, lhs, rhs) {}
      
  inline string name() override {
    return "Subtraction";
  }

  void Accept(Visitor* visitor) override;
};

#endif