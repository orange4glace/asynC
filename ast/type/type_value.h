#ifndef TYPE_VALUE_H_
#define TYPE_VALUE_H_

#include "ast/type/type.h"
#include "../operator.h"

struct TypeValue {

  bool lvalue;

  virtual TypeValue* ExecuteOperator(Operator op, TypeValue* rhs) = 0;

  virtual Type type() = 0;

  virtual void Print(std::ostream& str) const = 0;
  inline friend std::ostream& operator<<(std::ostream& str, TypeValue const& self) {
    self.Print(str);
    return str;
  }

};

#endif