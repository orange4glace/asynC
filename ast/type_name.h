#ifndef TYPE_NAME_H_
#define TYPE_NAME_H_

#include "node.h"
#include "ast/type_specifier.h"
#include "ast/abstract_declarator.h"

struct TypeNameNode : Node {
  TypeSpecifierNode *type_specifier;
  AbstractDeclaratorNode *abstract_declarator;

  inline TypeNameNode(TypeSpecifierNode *ts, AbstractDeclaratorNode *ad)
    : type_specifier(ts), abstract_declarator(ad) {}

  inline void Print() override {
    indent();
    cout << "[TypeName]\n";
    ii();
    type_specifier->Print();
    abstract_declarator->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif