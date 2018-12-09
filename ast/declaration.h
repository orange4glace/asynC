#ifndef DECLARATION_H_
#define DECLARATION_H_

#include "node.h"
#include "type_specifier.h"
#include "init_declarator.h"

struct DeclarationNode : Node {
  TypeSpecifierNode *type_specifier;
  InitDeclaratorNode *init_declarator;
  
  inline DeclarationNode(TypeSpecifierNode* ts, InitDeclaratorNode* id) {
    type_specifier = ts;
    init_declarator = id;
  }
  inline void Print() override {
    indent();
    cout << "[DeclarationNode]\n";
    ii();
    type_specifier->Print();
    init_declarator->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif