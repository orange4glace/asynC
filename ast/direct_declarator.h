#ifndef DIRECT_DECLARATOR_H_
#define DIRECT_DECLARATOR_H_

#include "node.h"
#include "identifier.h"

struct DirectDeclaratorNode : Node {
  IdentifierNode *identifier;

  inline DirectDeclaratorNode(IdentifierNode *id) {
    identifier = id;
  }
  inline void Print() override {
    indent();
    cout << "[DirectDeclarator]\n";
    ii();
    identifier->Print();
    di();
  }
};

#endif