#ifndef DECLARATOR_H_
#define DECLARATOR_H_

#include "node.h"
#include "direct_declarator.h"

struct DeclaratorNode : Node {
  DirectDeclaratorNode *direct_declarator;

  inline DeclaratorNode(DirectDeclaratorNode *dd) {
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