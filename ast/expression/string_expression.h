#ifndef STRING_EXPRESSION_H_
#define STRING_EXPRESSION_H_

#include "expression.h"

struct StringExpressionNode : ExpressionNode {
  
  inline StringExpressionNode() {}
      
  inline void Print() override {
  }

  void Accept(Visitor* visitor) override;
};

#endif