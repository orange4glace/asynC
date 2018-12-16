#ifndef FUNCTION_CALL_EXPRESSION_H_
#define FUNCTION_CALL_EXPRESSION_H_

#include "ast/identifier.h"
#include "ast/expression/expression.h"

struct FunctionCallExpressionNode : ExpressionNode {
  ExpressionNode* identifier;
  ExpressionNode* argument_expression_list;
  
  inline FunctionCallExpressionNode(ExpressionNode* fn_id, ExpressionNode* arg_exp_list)
      : identifier(fn_id), argument_expression_list(arg_exp_list) {
    assert(dynamic_cast<IdentifierExpressionNode*>(identifier));
  }

  inline void Print() override {
    indent();
    cout << "[FunctionCall]\n";
    ii();
    identifier->Print();
    indent();
    cout << "[ArgumentExpressionList]\n";
    ii();
    Node* arg = argument_expression_list;
    while (arg) {
      arg->Print();
      arg = arg->next;
    }
    di();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif