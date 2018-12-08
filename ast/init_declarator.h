#ifndef INIT_DECLARATOR_H_
#define INIT_DECLARATOR_H_

#include "node.h"
#include "initializer.h"

struct InitDeclaratorNode : Node {
  InitDeclaratorNode *next;
  inline InitDeclaratorNode() {

  }
  inline InitDeclaratorNode(InitializerNode *init) {

  }
  inline void Print() override {
    
  }
};

#endif