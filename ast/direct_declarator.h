#ifndef DIRECT_DECLARATOR_H_
#define DIRECT_DECLARATOR_H_

#include "node.h"
#include "identifier.h"
#include "ast/expression/constant_expression.h"

struct DirectDeclaratorNode : Node {
  IdentifierNode *identifier;
  ConstantExpressionNode *array_constant;

  inline DirectDeclaratorNode(IdentifierNode *id) {
    identifier = id;
    array_constant = nullptr;
  }
  inline void Print() override {
    indent();
    cout << "[DirectDeclarator]\n";
    ii();
    identifier->Print();
    if (array_constant) {
      indent();
      cout << "[ArrayConstant]\n";
      ii();
      array_constant->Print();
      di();
    }
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif