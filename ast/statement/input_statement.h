#ifndef INPUT_STATEMENT_H_
#define INPUT_STATEMENT_H_

#include "ast/statement/statement.h"

struct InputStatementNode : StatementNode {

  ExpressionNode *expression;

  inline InputStatementNode(ExpressionNode *exp)
    : expression(exp) {
  }

  inline void Print() override {
    indent();
    cout << "[InputStatement]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif