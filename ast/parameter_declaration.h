#ifndef PARAMETER_DECLARATION_H_
#define PARAMETER_DECLARATION_H_

#include "node.h"
#include "ast/type_specifier.h"
#include "ast/declarator.h"

struct ParameterDeclarationNode : Node {
  TypeSpecifierNode *type_specifier;
  DeclaratorNode *declarator;

  inline ParameterDeclarationNode(TypeSpecifierNode *ts, DeclaratorNode *decl) {
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
  }

  void Accept(Visitor* visitor) override;
};

#endif