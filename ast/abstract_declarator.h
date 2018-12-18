#ifndef ABSTRACT_DECLARATOR_H_
#define ABSTRACT_DECLARATOR_H_

#include "node.h"
#include "ast/pointer.h"
#include "direct_abstract_declarator.h"

struct AbstractDeclaratorNode : Node {
  PointerNode *pointer;
  DirectAbstractDeclaratorNode *direct_abstract_declarator;

  inline AbstractDeclaratorNode() {
    pointer = nullptr;
    direct_abstract_declarator = nullptr;
  }
  inline void Print() override {
    indent();
    cout << "[AbstractDeclaratorNode]\n";
    ii();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif