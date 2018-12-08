#ifndef INIT_DECLARATOR_H_
#define INIT_DECLARATOR_H_

#include "node.h"
#include "declarator.h"
#include "initializer.h"

struct InitDeclaratorNode : Node {
  InitDeclaratorNode *next;

  DeclaratorNode *declarator;
  InitializerNode *initializer;

  inline InitDeclaratorNode(DeclaratorNode *d) {
    declarator = d;
    initializer = nullptr;
    next = nullptr;
  }
  inline InitDeclaratorNode(DeclaratorNode* d, InitializerNode *init) {
    declarator = d;
    initializer = init;
    next = nullptr;
  }
  inline void Print() override {
    indent();
    cout << "[InitDeclarator]\n";
    ii();
    declarator->Print();
    if (initializer) initializer->Print();
    di();

    if (next != nullptr) next->Print();
  }
};

#endif