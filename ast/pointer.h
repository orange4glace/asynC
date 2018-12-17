#ifndef POINTER_NODE_H_
#define POINTER_NODE_H_

#include "node.h"

struct PointerNode : Node {
  
  inline PointerNode() {
  }
  inline void Print() override {
    indent();
    cout << "[Pointer]\n";
    ii();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif