#ifndef ASYNC_EXPRESSION_H_
#define ASYNC_EXPRESSION_H_

#include "ast/expression/expression.h"
#include "ast/statement/compound_statement.h"

struct AsyncExpressionNode : ExpressionNode {
  ExpressionNode *variable_capture_expression;
  CompoundStatementNode *compound_statement;
  
  inline AsyncExpressionNode(ExpressionNode *vcap, CompoundStatementNode *cs) {
    variable_capture_expression = vcap;
    compound_statement = cs;
  }
  
  inline void Print() override {
    indent();
    cout << "[AsyncExpression]\n";
    ii();
    indent();
    cout << "[VariableCapture]\n";
    ii();
    Node* exp = variable_capture_expression;
    while (exp) {
      exp->Print();
      exp = exp->next;
    }
    di();
    compound_statement->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif