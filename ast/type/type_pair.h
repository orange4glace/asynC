#ifndef TYPE_PAIR_H_
#define TYPE_PAIR_H_

#include "../operator.h"
#include "type.h"

#include <string>

using namespace std;

struct TypePair {
  Operator op;
  Type type1, type2;

  TypePair(Operator op, Type t1, Type t2) {
    type1 = t1;
    type2 = t2;
  }

};

#endif