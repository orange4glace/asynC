#include "ast/expression/expression_include.h"
#include "ast/parser/visitor.h"

void AssignmentExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void BinaryExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void UnaryExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ConstantExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void IdentifierExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ArrayExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void FunctionCallExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void AsyncExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void CastExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void StringExpressionNode::Accept(Visitor *visitor) { }

void ConditionalExpressionNode::Accept(Visitor *visitor) { }