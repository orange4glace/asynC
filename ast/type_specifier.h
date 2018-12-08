#ifndef TYPE_SPECIFIER_H_
#define TYPE_SPECIFIER_H_

#include "node.h"
#include "type/type.h"

struct TypeSpecifierNode : Node {
  Type type;

  inline TypeSpecifierNode(Type type) : type(type) {}
  inline void Print() override {
    indent();
    cout << "[TypeSpecifierNode] " << type << "\n";
  }
};

#endif