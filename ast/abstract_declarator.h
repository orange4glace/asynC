#ifndef ABSTRACT_DECLARATOR_H_
#define ABSTRACT_DECLARATOR_H_

#include "node.h"
#include "direct_abstract_declarator.h"

struct AbstractDeclaratorNode : Node {
  DirectAbstractDeclaratorNode *direct_abstract_declarator;

  inline AbstractDeclaratorNode(DirectAbstractDeclaratorNode *dad) {
    direct_abstract_declarator = dad;
  }
  inline void Print() override {
    indent();
    cout << "[AbstractDeclaratorNode]\n";
    ii();
    direct_abstract_declarator->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif