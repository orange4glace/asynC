#ifndef DIRECT_ABSTRACT_DECLARATOR_H_
#define DIRECT_ABSTRACT_DECLARATOR_H_

#include "node.h"
#include "identifier.h"
#include "ast/expression/constant_expression.h"

struct DirectAbstractDeclaratorNode : Node {

  inline DirectAbstractDeclaratorNode() {
  }
  inline void Print() override {
    indent();
    cout << "[DirectAbstractDeclarator]\n";
  }

  void Accept(Visitor* visitor) override;
};

#endif