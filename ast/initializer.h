#ifndef INITIALIZER_H_
#define INITIALIZER_H_

#include "node.h"
#include "expression/assignment_expression.h"

struct InitializerNode : Node {
  ExpressionNode *expression;

  inline InitializerNode(ExpressionNode *exp) {
    expression = exp;
  }
  inline void Print() override {
    indent();
    cout << "[Initializer]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif