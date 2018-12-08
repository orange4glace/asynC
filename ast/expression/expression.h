#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "../node.h"

struct ExpressionNode : Node {

  ExpressionNode() {
  }
  
  virtual void Assign(ExpressionNode *rhs) = 0;
};

#endif