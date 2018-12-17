#ifndef NEW_EXPRESSION_H_
#define NEW_EXPRESSION_H_

#include "ast/type_specifier.h"
#include "expression.h"

struct NewExpressionNode : ExpressionNode {
  TypeSpecifierNode *type_specifier;
  
  inline NewExpressionNode(TypeSpecifierNode *ts)
      : type_specifier(ts) {}

  inline void Print() override {
    indent();
    cout << "[NewExpression]\n";
    ii();
    type_specifier->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif