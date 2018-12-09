#ifndef COMPOUND_STATEMENT_H_
#define COMPOUND_STATEMENT_H_

#include "ast/statement/statement.h"

#include <list>

struct CompoundStatementNode : StatementNode {

  Node* node_list;

  inline CompoundStatementNode(Node* node_list) : node_list(node_list) {
  }

  inline void Print() override {
    indent();
    cout << "[CompoundStatement]" << endl;
  }

  void Accept(Visitor* visitor) override;
};

#endif