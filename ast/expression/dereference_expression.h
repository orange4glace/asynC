#ifndef DEREFERENCE_EXPRESSION_H_
#define DEREFERENCE_EXPRESSION_H_

#include "expression.h"
#include "ast/type/integer.h"

struct DereferenceExpressionNode : ExpressionNode {
  ExpressionNode *expression;

  DereferenceExpressionNode(ExpressionNode *exp) 
    : expression(exp) {
  }
      
  inline void Print() override {
    indent();
    cout << "[Dereference]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif