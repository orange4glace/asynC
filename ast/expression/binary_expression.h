#ifndef BINARY_EXPRESSION_H_
#define BINARY_EXPRESSION_H_

#include "expression.h"
#include "ast/operator.h"

struct BinaryExpressionNode : ExpressionNode {
  ExpressionNode *lhs;
  ExpressionNode *rhs;
  Operator op;
  
  inline BinaryExpressionNode(Operator op, ExpressionNode *lhs, ExpressionNode *rhs) {
    this->op = op;
    this->lhs = lhs;
    this->rhs = rhs;
  }

  inline void Print() override {
    indent();
    cout << "[" << OperatorToString(op) << "]\n";
    ii();
    lhs->Print();
    rhs->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif