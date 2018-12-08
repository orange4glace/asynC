#ifndef INITIALIZER_H_
#define INITIALIZER_H_

#include "node.h"
#include "expression/assignment_expression.h"

struct InitializerNode : Node {
  AssignmentExpressionNode *assignment_expression;

  inline InitializerNode(AssignmentExpressionNode *exp) {
    assignment_expression = exp;
  }
  inline void Print() override {
    indent();
    cout << "[Initializer]\n";
    ii();
    assignment_expression->Print();
    di();
  }
};

#endif