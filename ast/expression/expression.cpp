#include "expression_include.h"

void IdentifierExpression::Accept(Visitor* visitor) {
  visitor->Visit(this);
}