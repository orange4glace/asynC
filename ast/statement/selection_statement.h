#ifndef SELECTION_STATEMENT_H_
#define SELECTION_STATEMENT_H_

#include "ast/expression/expression.h"
#include "ast/statement/statement.h"
/*
selection_statement
  : IF '(' expression ')' statement
  {
    $$ = new SelectionStatementNode($3, $5);
  }
  | IF '(' expression ')' statement ELSE statement {
    $$ = new SelectionStatementNode($3, $5, $7);
  }
  ;

*/

struct SelectionStatementNode : StatementNode {

  ExpressionNode *cond;
  StatementNode *stmt1;
  StatementNode *stmt2;

  inline SelectionStatementNode(ExpressionNode *cond, StatementNode *stmt1) {
      this->cond = cond;
      this->stmt1 = stmt1;
      this->stmt2 = nullptr;
  }
  inline SelectionStatementNode(ExpressionNode *cond, StatementNode *stmt1, StatementNode *stmt2) {
      this->cond = cond;
      this->stmt1 = stmt1;
      this->stmt2 = stmt2;
  }

  inline void Print() override {
    indent();
    cout << "[SelectionStatement]" << endl;
    ii();
    cond->Print();
    stmt1->Print();
    if(stmt2) stmt2->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif