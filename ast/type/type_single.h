#ifndef TYPE_SINGLE_H_
#define TYPE_SINGLE_H_

#include "../operator.h"
#include "type.h"

#include <string>

using namespace std;

struct TypeSingle {
  Operator op;
  Type type1;

  inline TypeSingle(Operator op, Type t1) {
    this->op = op;
    type1 = t1;
  }

  inline bool operator<(const TypeSingle& rhs) const {
    int op1 = static_cast<int>(op);
    int op2 = static_cast<int>(rhs.op);
    if (op1 < op2) return true;
    if (op1 == op2) 
      if (static_cast<int>(type1) < static_cast<int>(rhs.type1)) return true;
    return false;
  }

};

#endif