#ifndef IDENTIFIER_TYPE_H_
#define IDENTIFIER_TYPE_H_

#include "ast/identifier.h"

#include <string>

using namespace std;

struct Identifier {

  string id;

  inline Identifier(IdentifierNode *identifier_node) {
    id = identifier_node->id;
  }

  inline Identifier(string id) {
    this->id = id;
  }

  static inline Type _type() {
    return Type::IDENTIFIER;
  }

};

#endif