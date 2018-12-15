#ifndef UNARY_EXPRESSION_H_
#define UNARY_EXPRESSION_H_

#include "expression.h"
#include "ast/operator.h"

struct UnaryExpressionNode : ExpressionNode {
  ExpressionNode *lhs;
  Operator op;
  
  inline UnaryExpressionNode(Operator op, ExpressionNode *lhs) {
    this->op = op;
    this->lhs = lhs;
  }

  inline void Print() override {
    indent();
    cout << "[" << OperatorToString(op) << "]\n";
    ii();
    lhs->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif