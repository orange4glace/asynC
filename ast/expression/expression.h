#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "ast/type/type_value.h"
#include "ast/statement/statement.h"

struct ExpressionNode : StatementNode {

  TypeValue *type_value;

  ExpressionNode() {
  }
};

#endif