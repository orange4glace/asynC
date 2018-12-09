#ifndef VISITOR_H_
#define VISITOR_H_

#include "ast/parser/symbol_table.h"
#include "ast/statement/statement_include.h"
#include "ast/expression/expression_include.h"
#include "ast/type/type.h"
#include "ast/type/type_value.h"
#include "ast/type/type_value_factory.h"
#include "ast/declaration.h"
#include "ast/declarator.h"
#include "ast/direct_declarator.h"
#include "ast/identifier.h"
#include "ast/init_declarator.h"
#include "ast/initializer.h"
#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/function_definition.h"
#include "ast/operator.h"

extern SymbolTable *symbol_table;

struct Visitor {
  TypeSpecifierNode *type_specifier;
  IdentifierNode *identifier;

  ExpressionNode *expression;
  TypeValue* type_value;
  StatementNode* statement;

  Visitor() {
    type_specifier = nullptr;
    identifier = nullptr;
    expression = nullptr;
    type_value = nullptr;
  }

  void Visit(DeclarationNode *node) {
    indent();
    cout << "(DeclarationNode)\n";
    ii();
    node->type_specifier->Accept(this);
    node->init_declarator->Accept(this);
    di();
  }

  void Visit(TypeSpecifierNode *node) {
    indent();
    cout << "(TypeSpecifier) " << static_cast<int>(node->type) << "\n";
    ii();
    type_specifier = node;
    type_value = TypeValueFactory::Create(node->type);
    di();
  }

  void Visit(InitDeclaratorNode *node) {
    indent();
    cout << "(InitDeclarator)\n";
    ii();
    // We know the Type since we visit TypeSpecifierNode
    // before visiting InitDeclarationNode
    node->declarator->Accept(this);
    // Now we have an complete typevalue and identifier
    IdentifierNode* declarator_identifier = identifier;
    TypeValue* declarator_type_value = type_value;
    if (!node->initializer) {
      symbol_table->AddSymbol(declarator_identifier, type_value);
      indent();
      cout << "(InitDeclarator) AddSymbol " << declarator_identifier->id << " " << *type_value << "\n";
      return;
    }
    node->initializer->Accept(this);
    TypeValue* initializer_type_value = type_value;
    type_value = declarator_type_value->ExecuteOperator(ASSIGNMENT, initializer_type_value);
    symbol_table->AddSymbol(declarator_identifier, type_value);
    indent();
    cout << "(InitDeclarator) AddSymbol " << declarator_identifier->id << " " << *type_value << "\n";
    di();
  }

  void Visit(DeclaratorNode *node) {
    node->direct_declarator->Accept(this);
  }

  void Visit(DirectDeclaratorNode *node) {
    node->identifier->Accept(this);
  }

  void Visit(IdentifierNode *node) {
    indent();
    cout << "(Identifier) " << node->id << "\n";
    identifier = node;
  }

  void Visit(InitializerNode *node) {
    node->expression->Accept(this);
  }

  void Visit(AssignmentExpressionNode *node) {
    indent();
    cout << "(Assignment)\n";
    ii();
    type_value = nullptr;
    if (node->exp) {
      node->exp->Accept(this);
      indent();
      cout << *type_value << endl;
      return;
    }
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    lhs->ExecuteOperator(ASSIGNMENT, rhs);
    type_value = lhs;
    indent();
    cout << *type_value << endl;
    di();
  }

  void Visit(IdentifierExpressionNode *node) {
    node->identifier->Accept(this);
    type_value = symbol_table->GetSymbol(node->identifier);
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

  void Visit(FunctionDefinitionNode *node) {
    node->type_specifier->Accept(this);
    TypeValue *return_type = type_value;
    node->declarator->Accept(this);
    IdentifierNode *function_identifier = identifier;
    node->compound_statement->Accept(this);
    CompoundStatementNode *function_compound_statement 
        = static_cast<CompoundStatementNode*>(statement);
    
  }

  void Visit(CompoundStatementNode *node) {
    statement = node;
  }

};

extern Visitor *visitor;

#endif