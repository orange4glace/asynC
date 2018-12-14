#ifndef ARRAY_EXPRESSION_H_
#define ARRAY_EXPRESSION_H_

#include "expression.h"

struct ArrayExpressionNode : ExpressionNode {
  ExpressionNode* expression;
  ExpressionNode* index;
  
  inline ArrayExpressionNode(ExpressionNode *exp, ExpressionNode *idx)
      : expression(exp), index(idx) {}

  inline void Print() override {
    indent();
    cout << "[ArrayExpressionNode]\n";
    ii();
    expression->Print();
    index->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif