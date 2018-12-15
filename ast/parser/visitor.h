#ifndef VISITOR_H_
#define VISITOR_H_

#include "ast/parser/symbol_table.h"
#include "ast/statement/statement_include.h"
#include "ast/expression/expression_include.h"
#include "ast/type/type.h"
#include "ast/type/type_value.h"
#include "ast/type/type_value_factory.h"
#include "ast/type/identifier.h"
#include "ast/type/function.h"
#include "ast/type/function_parameter.h"
#include "ast/declaration.h"
#include "ast/declarator.h"
#include "ast/abstract_declarator.h"
#include "ast/direct_declarator.h"
#include "ast/direct_abstract_declarator.h"
#include "ast/identifier.h"
#include "ast/init_declarator.h"
#include "ast/initializer.h"
#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/type_name.h"
#include "ast/function_definition.h"
#include "ast/parameter_declaration.h"
#include "ast/operator.h"

struct Visitor {
  TypeSpecifierNode *type_specifier;

  ExpressionNode *expression;
  Identifier *identifier;
  TypeValue *type_value;
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
    Identifier* declarator_identifier = identifier;
    TypeValue* declarator_type_value = type_value;
    // TODO : COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY COPY
    symbol_table->PushStackFrameBack(declarator_type_value);
    if (!node->initializer) {
      symbol_table->AddSymbol(declarator_identifier, type_value);
      indent();
      cout << "(InitDeclarator) AddSymbol " << declarator_identifier->id << " " << *type_value << "\n";
      return;
    }
    node->initializer->Accept(this);
    TypeValue* initializer_type_value = type_value;
    type_value = declarator_type_value->ExecuteOperator(Operator::ASSIGNMENT, initializer_type_value);
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
    identifier = new Identifier(node);
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
    lhs->ExecuteOperator(Operator::ASSIGNMENT, rhs);
    type_value = lhs;
    indent();
    cout << *type_value << endl;
    di();
  }

  void Visit(IdentifierExpressionNode *node) {
    node->identifier->Accept(this);
    type_value = symbol_table->GetSymbol(identifier);
  }

  void Visit(BinaryExpressionNode *node) {
    type_value = nullptr;
    node->rhs->Accept(this);
    TypeValue *rhs = type_value;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    type_value = lhs->ExecuteOperator(node->op, rhs);
  }

  void Visit(UnaryExpressionNode *node) {
    type_value = nullptr;
    node->lhs->Accept(this);
    TypeValue *lhs = type_value;
    type_value = lhs->ExecuteOperator(node->op);
  }

  void Visit(ConstantExpressionNode *node) {
    type_value = node->type_value;
    symbol_table->PushStackFrameBack(type_value);
  }

  void Visit(FunctionDefinitionNode *node) {
    Function* function = new Function();
    node->type_specifier->Accept(this);
    TypeValue *return_type = type_value;
    node->declarator->Accept(this);
    Identifier *function_identifier = identifier;
    ParameterDeclarationNode *pdecl = node->parameter_declaration_list;
    SymbolTable *fn_symbol_table = new SymbolTable(symbol_table);
    while (pdecl) {
      pdecl->Accept(this);
      Identifier *fn_parameter_identifier = identifier;
      TypeValue *fn_parameter_type_value = type_value;
      FunctionParameter *fn_parameter =
          new FunctionParameter(fn_parameter_identifier, fn_parameter_type_value);
      fn_symbol_table->AddSymbol(fn_parameter_identifier, fn_parameter_type_value);
      function->parameters.push_back(fn_parameter);
      pdecl = static_cast<ParameterDeclarationNode*>(pdecl->next);
    }
    node->compound_statement->Accept(this);
    CompoundStatementNode *function_compound_statement 
        = static_cast<CompoundStatementNode*>(statement);
        
    SymbolTable *saved_symbol_table = symbol_table;
    symbol_table = fn_symbol_table;

  

    symbol_table = saved_symbol_table;
  }

  void Visit(ParameterDeclarationNode *node) {

  }

  void Visit(CompoundStatementNode *node) {
    Node *node_list = node->node_list;
    while (node_list) {
      node_list->Accept(this);
      node_list = node_list->next;
    }
  }

  void Visit(IterationStatementNode *node) {
    symbol_table->Push();
    symbol_table->AppendCode("s", "loop_start:");
    node->cond->Accept(this);
    symbol_table->AppendCode("ssd", "cmp", type_value->GetStackFrameAddress(), 0);
    symbol_table->AppendCode("ss", "je", "loop_end");
    node->stmt->Accept(this);
    symbol_table->ClearStackFrame();
    symbol_table->AppendCode("ss", "jmp", "loop_start");
    symbol_table->AppendCode("s", "loop_end:");
    symbol_table->Pop();
  }

  void Visit(PrintStatementNode *node) {
    node->expression->Accept(this);
    symbol_table->AppendCode("ss", "prn", type_value->GetStackFrameAddress());
  }

};

extern Visitor *visitor;

#endif