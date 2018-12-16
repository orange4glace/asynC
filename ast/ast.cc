#include "ast/ast.h"
#include "ast/declarator.h"
#include "ast/abstract_declarator.h"
#include "ast/declaration.h"
#include "ast/direct_declarator.h"
#include "ast/direct_abstract_declarator.h"
#include "ast/identifier.h"
#include "ast/init_declarator.h"
#include "ast/initializer.h"
#include "ast/type_specifier.h"
#include "ast/function_definition.h"
#include "ast/parameter_declaration.h"
#include "ast/type_name.h"
#include "ast/parser/visitor.h"

#include "ast/type/integer.h"
#include <iostream>

int indent_count = 0;
void indent() {
  for (int i = 0; i < indent_count; i ++)
  std::cout << "  ";
}
void ii() { indent_count++; }
void di() { indent_count--; }

int global_id = 0;

void init_ast() {
  Void::Initialize();
  Integer::Initialize();
}

void DeclarationNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void DeclaratorNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void DirectDeclaratorNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void IdentifierNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void InitDeclaratorNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void InitializerNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void TypeSpecifierNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void FunctionDefinitionNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void ParameterDeclarationNode::Accept(Visitor *visitor) { visitor->Visit(this); }
void AbstractDeclaratorNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void DirectAbstractDeclaratorNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }
void TypeNameNode::Accept(Visitor *visitor) { assert(false); /* visitor->Visit(this); */ }