#ifndef FOR_STATEMENT_H_
#define FOR_STATEMENT_H_

#include "ast/expression/expression.h"
#include "ast/declaration.h"
#include "ast/statement/statement.h"

struct ForStatementNode : StatementNode {

  ExpressionNode *init_expression;
  DeclarationNode *init_declaration;
  StatementNode *condition;
  ExpressionNode *iterator;
  StatementNode *statement;

  inline ForStatementNode(ExpressionNode *init_exp,
      StatementNode *cond, ExpressionNode *iter, StatementNode *stmt)
    : init_expression(init_exp), init_declaration(nullptr), condition(cond), iterator(iter), statement(stmt) {
    }

  inline ForStatementNode(DeclarationNode *init_decl,
      StatementNode *cond, ExpressionNode *iter, StatementNode *stmt)
    : init_expression(nullptr), init_declaration(init_decl), condition(cond), iterator(iter), statement(stmt) {
    }

  inline void Print() override {
    indent();
    cout << "[ForStatement]" << endl;
    ii();
    if (init_expression) init_expression->Print();
    if (init_declaration) init_declaration->Print();
    condition->Print();
    iterator->Print();
    statement->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif