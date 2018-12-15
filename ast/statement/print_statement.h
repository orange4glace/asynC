#ifndef PRINT_STATEMENT_H_
#define PRINT_STATEMENT_H_

#include "ast/statement/statement.h"

struct PrintStatementNode : StatementNode {

  ExpressionNode *expression;

  inline PrintStatementNode(ExpressionNode *exp)
    : expression(exp) {
  }

  inline void Print() override {
    indent();
    cout << "[PrintStatement]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif