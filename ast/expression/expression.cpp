#include "ast/expression/expression_include.h"
#include "ast/parser/visitor.h"

void AdditionExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void AssignmentExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ConstantExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void IdentifierExpressionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ArrayExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void FunctionCallExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void AsyncExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void CastExpressionNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void InclusiveORExpressionNode::Accept(Visitor *visitor) { }
void LogicalANDExpressionNode::Accept(Visitor *visitor) { }
void LogicalORExpressionNode::Accept(Visitor *visitor) { }
void StringExpressionNode::Accept(Visitor *visitor) { }
void SubtractionExpressionNode::Accept(Visitor *visitor) { }

void ConditionalExpressionNode::Accept(Visitor *visitor) { }