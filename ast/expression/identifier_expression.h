#ifndef IDENTIFIER_EXPRESSION_H_
#define IDENTIFIER_EXPRESSION_H_

#include "expression.h"
#include "../identifier.h"

struct IdentifierExpressionNode : ExpressionNode {
  IdentifierNode* identifier;
  
  inline IdentifierExpressionNode(IdentifierNode *id)
      : identifier(id) {}

  inline void Print() override {
    indent();
    cout << "[IdentifierExpression]\n";
    ii();
    identifier->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif