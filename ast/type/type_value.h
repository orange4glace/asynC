#ifndef TYPE_VALUE_H_
#define TYPE_VALUE_H_

#include "../operator.h"

struct TypeValue {

  virtual TypeValue* ExecuteOperator(Operator op, TypeValue* rhs) = 0;

  virtual Type type() = 0;

};

#endif