#ifndef FUNCTION_DEFINITION_H_
#define FUNCTION_DEFINITION_H_

#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/declarator.h"
#include "ast/parameter_declaration.h"
#include "ast/statement/compound_statement.h"

struct FunctionDefinitionNode : Node {
  TypeSpecifierNode *type_specifier;
  DeclaratorNode *declarator;
  ParameterDeclarationNode *parameter_declaration_list;
  CompoundStatementNode *compound_statement;

  inline FunctionDefinitionNode(
      TypeSpecifierNode *ts,
      DeclaratorNode *dl,
      ParameterDeclarationNode *pd,
      CompoundStatementNode *cs
  ) : type_specifier(ts), declarator(dl),
      parameter_declaration_list(pd), compound_statement(cs) {
  }

  inline void Print() override {
    indent();
    cout << "[FunctionDefinition]\n";
    ii();
    type_specifier->Print();
    declarator->Print();
    indent();
    cout << "[ParameterDeclaratorList]\n";
    ii();
    Node *param = parameter_declaration_list;
    while (param) {
      param->Print();
      param = param->next;
    }
    di();
    compound_statement->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif