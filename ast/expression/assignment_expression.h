#ifndef ASSIGNMENT_EXPRESSION_H_
#define ASSIGNMENT_EXPRESSION_H_

#include "expression.h"

struct AssignmentExpressionNode : ExpressionNode {
  ExpressionNode *exp;
  ExpressionNode *lhs;
  ExpressionNode *rhs;
  
  inline AssignmentExpressionNode(ExpressionNode *exp) {
    this->exp = exp;
  }
  inline AssignmentExpressionNode(ExpressionNode *lhs, ExpressionNode *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
    this->exp = nullptr;
  }
  inline void Print() override {
    indent();
    cout << "[Assignment]\n";
    ii();
    if (exp) exp->Print();
    else {
      lhs->Print();
      rhs->Print();
    }
    di();
  }
};

#endif