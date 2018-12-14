#ifndef ITERATION_STATEMENT_H_
#define ITERATION_STATEMENT_H_

#include "ast/statement/statement.h"
#include "ast/expression/expression_include.h"
/*
iteration_statement
  : WHILE '(' expression ')' statement
  {
    $$ = new IterationStatementNode($3, $5);
  }
*/

struct IterationStatementNode : StatementNode {

  ExpressionNode *cond;
  StatementNode *stmt;

  inline IterationStatementNode(ExpressionNode *cond, StatementNode *stmt) {
      this->cond = cond;
      this->stmt = stmt;
  }

  inline void Print() override {
    indent();
    cout << "[IterationStatement]" << endl;
    ii();
    cond->Print;
    stmt->Print;
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif