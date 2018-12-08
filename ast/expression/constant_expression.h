#ifndef CONSTANT_EXPRESSION_H_
#define CONSTANT_EXPRESSION_H_

#include "expression.h"
#include "ast/type/integer.h"

struct ConstantExpressionNode : ExpressionNode {
  Integer *type_value_;

  inline Integer* type_value() {
    return type_value_;
  }
      
  inline void Print() override {
    indent();
    cout << "[Constant] " << type_value_->value << "\n";
  }
};

#endif