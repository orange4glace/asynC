#ifndef TYPE_PAIR_H_
#define TYPE_PAIR_H_

#include "../operator.h"
#include "type.h"

#include <string>

using namespace std;

struct TypePair {
  Operator op;
  Type type1, type2;

  inline TypePair(Operator op, Type t1, Type t2) {
    this->op = op;
    type1 = t1;
    type2 = t2;
  }

  inline bool operator<(const TypePair& rhs) const {
    if (op < rhs.op) return true;
    if (op == rhs.op) {
      if (static_cast<int>(type1) < static_cast<int>(rhs.type1)) return true;
      if (static_cast<int>(type1) == static_cast<int>(rhs.type1))
        if (static_cast<int>(type2) < static_cast<int>(rhs.type2)) return true;
    }
    return false;
  }

};

#endif