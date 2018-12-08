#ifndef VISITOR_H_
#define VISITOR_H_

#include "ast/parser/symbol_table.h"
#include "ast/expression/expression_include.h"
#include "ast/declaration.h"
#include "ast/declarator.h"
#include "ast/direct_declarator.h"
#include "ast/identifier.h"
#include "ast/init_declarator.h"
#include "ast/initializer.h"
#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/operator.h"
#include "ast/type/type.h"
#include "ast/type/type_value.h"
#include "ast/type/type_value_factory.h"

extern SymbolTable *symbol_table;

struct Visitor {
  TypeSpecifierNode *type_specifier;
  IdentifierNode *identifier;

  ExpressionNode *expression;
  TypeValue* type_value;

  Visitor() {
    type_specifier = nullptr;
    identifier = nullptr;
    expression = nullptr;
    type_value = nullptr;
  }

  void Visit(DeclarationNode *node) {
    node->type_specifier->Accept(this);
    node->init_declarator->Accept(this);
  }

  void Visit(TypeSpecifierNode *node) {
    type_specifier = node;
    type_value = TypeValueFactory::Create(node->type);
  }

  void Visit(InitDeclaratorNode *node) {
    // We know the Type since we visit TypeSpecifierNode
    // before visiting InitDeclarationNode
    node->declarator->Accept(this);
    // Now we have an complete typevalue and identifier
    TypeValue* declarator_type_value = type_value;
    if (!node->initializer) {
      symbol_table->AddSymbol(identifier, type_value);
      return;
    }
    node->initializer->Accept(this);
    TypeValue* initializer_type_value = type_value;
    type_value = declarator_type_value->ExecuteOperator(ASSIGNMENT, initializer_type_value);
    symbol_table->AddSymbol(identifier, type_value);
  }

  void Visit(DeclaratorNode *node) {
    node->direct_declarator->Accept(this);
  }

  void Visit(DirectDeclaratorNode *node) {
    node->identifier->Accept(this);
  }

  void Visit(IdentifierNode *node) {
    identifier = node;
  }

  void Visit(InitializerNode *node) {
    node->assignment_expression->Accept(this);
  }

  void Visit(AssignmentExpressionNode *node) {
    type_value = nullptr;
    if (node->exp) {
      node->exp->Accept(this);
      return;
    }
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    lhs->ExecuteOperator(ASSIGNMENT, rhs);
    type_value = lhs;
  }

  void Visit(IdentifierExpressionNode *node) {
    expression = node;
    node->identifier->Accept(this);
  }

  void Visit(AdditionExpressionNode *node) {
    type_value = nullptr;
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    type_value = lhs->ExecuteOperator(ADDITION, rhs);
  }

  void Visit(ConstantExpressionNode *node) {
    type_value = node->type_value();
  }

};

extern Visitor *visitor;

#endif