#ifndef CAST_EXPRESSION_H_
#define CAST_EXPRESSION_H_

#include "ast/type_name.h"
#include "ast/abstract_declarator.h"
#include "expression.h"

struct CastExpressionNode : ExpressionNode {
  TypeNameNode* type_name;
  ExpressionNode* expression;
  
  inline CastExpressionNode(TypeNameNode *tn, ExpressionNode *exp)
      : type_name(tn), expression(exp) {}

  inline void Print() override {
    indent();
    cout << "[CastExpressionNode]\n";
    ii();
    type_name->Print();
    expression->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif