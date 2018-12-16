#include "statement_include.h"
#include "ast/parser/visitor.h"

void CompoundStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void IterationStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void SelectionStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ReturnStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void PrintStatementNode::Accept(Visitor *visitor) { visitor->Visit(this); }