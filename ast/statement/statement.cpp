#include "statement_include.h"
#include "ast/parser/visitor.h"

void CompoundStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }