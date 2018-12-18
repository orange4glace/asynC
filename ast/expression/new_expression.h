#ifndef NEW_EXPRESSION_H_
#define NEW_EXPRESSION_H_

#include "ast/type_specifier.h"
#include "ast/abstract_declarator.h"
#include "expression.h"

struct NewExpressionNode : ExpressionNode {
  TypeSpecifierNode *type_specifier;
  AbstractDeclaratorNode *abstract_declarator;
  
  inline NewExpressionNode(TypeSpecifierNode *ts, AbstractDeclaratorNode *adecl)
      : type_specifier(ts), abstract_declarator(adecl) {}

  inline void Print() override {
    indent();
    cout << "[NewExpression]\n";
    ii();
    type_specifier->Print();
    if (abstract_declarator) abstract_declarator->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif