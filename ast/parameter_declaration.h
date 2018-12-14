#ifndef PARAMETER_DECLARATION_H_
#define PARAMETER_DECLARATION_H_

#include "node.h"
#include "ast/type_specifier.h"
#include "ast/declarator.h"

struct ParameterDeclarationNode : Node {
  TypeSpecifier *type_specifier;
  Declarator *declarator;

  inline ParameterDeclarationNode(TypeSpecifier *ts, Declarator *decl) {
    type_specifier = ts;
    declarator = decl;
  }
  inline void Print() override {
    indent();
    cout << "[ParameterDeclaration]\n";
    ii();
    type_specifier->Print();
    declarator->Print();
    di();
    if (next) next->Print();
  }

  void Accept(Visitor* visitor) override;
};

#endif