#ifndef RETURN_STATEMENT_H_
#define RETURN_STATEMENT_H_

#include "ast/statement/statement.h"

struct ReturnStatementNode : StatementNode {

  ExpressionNode *expression;

  inline ReturnStatementNode()
    : expression(nullptr) {
  }

  inline ReturnStatementNode(ExpressionNode *exp)
    : expression(exp) {
  }

  inline void Print() override {
    indent();
    cout << "[ReturnStatement]\n";
    ii();
    if (expression)
      expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif