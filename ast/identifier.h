#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include "node.h"

struct IdentifierNode : Node {
  string id;

  inline IdentifierNode(char *id) {
    this->id = string(id);
  }
  inline void Print() override {
    indent();
    cout << "[Identifier] " << id << "\n";
  }

  void Accept(Visitor* visitor) override;
};

#endif