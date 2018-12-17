#ifndef DECLARATOR_H_
#define DECLARATOR_H_

#include "ast/node.h"
#include "ast/direct_declarator.h"
#include "ast/pointer.h"

struct DeclaratorNode : Node {
  PointerNode *pointer;
  DirectDeclaratorNode *direct_declarator;

  inline DeclaratorNode(DirectDeclaratorNode *dd) {
    pointer = nullptr;
    direct_declarator = dd;
  }
  inline void Print() override {
    indent();
    cout << "[Declarator]\n";
    ii();
    direct_declarator->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif