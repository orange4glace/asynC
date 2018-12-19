#ifndef RUN_STATEMENT_H_
#define RUN_STATEMENT_H_

#include "ast/statement/statement.h"

struct RunStatementNode : StatementNode {

  ExpressionNode *expression;

  inline RunStatementNode(ExpressionNode *exp)
    : expression(exp) {
  }

  inline void Print() override {
    indent();
    cout << "[RunStatementNode]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif