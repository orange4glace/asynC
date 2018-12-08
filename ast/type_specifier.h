#ifndef TYPE_SPECIFIER_H_
#define TYPE_SPECIFIER_H_

#include "node.h"

struct TypeSpecifierNode : Node {
  string type;

  inline TypeSpecifierNode(char* s) {
    type = string(s);
  }
  inline void Print() override {
    indent();
    cout << "[TypeSpecifierNode] " << type << "\n";
  }
};

#endif