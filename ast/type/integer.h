#ifndef INTEGER_H_
#define INTEGER_H_

#include "type_value_base.h"

struct Integer : TypeValueBase<Integer> {
  int value;

  inline static void Initialize() {
    Integer::AddOperatorFunction(
      TypePair(ADDITION, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);
        Integer* integer = new Integer();
        integer->value = lhs->value + rhs->value;
        return integer;
      }
    );
  }

  static inline Type _type() {
    return INTEGER;
  }

};

#endif