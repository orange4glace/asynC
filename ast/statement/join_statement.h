#ifndef JOIN_STATEMENT_H_
#define JOIN_STATEMENT_H_

#include "ast/statement/statement.h"

struct JoinStatementNode : StatementNode {

  ExpressionNode *expression;

  inline JoinStatementNode(ExpressionNode *exp)
    : expression(exp) {
  }

  inline void Print() override {
    indent();
    cout << "[JoinStatementNode]\n";
    ii();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif