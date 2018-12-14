#ifndef TYPE_SPECIFIER_H_
#define TYPE_SPECIFIER_H_

#include "node.h"
#include "type/type.h"

struct TypeSpecifierNode : Node {
  Type type;

  inline TypeSpecifierNode(Type type) : type(type) {}
  inline void Print() override {
    indent();
    cout << "[TypeSpecifier] ";
    switch (type) {
    case Type::VOID :
      cout << "VOID";
      break;
    case Type::INTEGER :
      cout << "INT";
      break;
    case Type::FUNCTION :
      cout << "FUNCTION";
      break;
    default :
      cout << "UNKNOWN";
      break;
    }
    cout << "\n";
  }

  void Accept(Visitor* visitor) override;
};

#endif