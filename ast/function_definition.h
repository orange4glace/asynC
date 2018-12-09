#ifndef FUNCTION_DEFINITION_H_
#define FUNCTION_DEFINITION_H_

#include "ast/node.h"
#include "ast/type_specifier.h"
#include "ast/declarator.h"
#include "ast/statement/compound_statement.h"

struct FunctionDefinitionNode : Node {
  TypeSpecifierNode *type_specifier;
  DeclaratorNode *declarator;
  CompoundStatementNode *compound_statement;

  inline FunctionDefinitionNode(
      TypeSpecifierNode *ts,
      DeclaratorNode *dl,
      CompoundStatementNode *cs
  ) : type_specifier(ts), declarator(dl), compound_statement(cs) {
  }

  inline void Print() override {
    indent();
    cout << "[FunctionDefinition]\n";
    ii();
    type_specifier->Print();
    declarator->Print();
    compound_statement->Print();
    di();
  }

  void Accept(Visitor* visitor) override;
};

#endif