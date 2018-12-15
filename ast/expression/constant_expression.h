#ifndef CONSTANT_EXPRESSION_H_
#define CONSTANT_EXPRESSION_H_

#include "expression.h"
#include "ast/type/integer.h"

struct ConstantExpressionNode : ExpressionNode {

  ConstantExpressionNode(int val) {
    Integer *integer = new Integer();
    integer->value = val;
    type_value = integer;
  }
      
  inline void Print() override {
    indent();
    cout << "[Constant]\n";
    ii();
    type_value->Print(cout);
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif