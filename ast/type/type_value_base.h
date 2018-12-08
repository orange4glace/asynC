#ifndef TYPE_VALUE_BASE_H_
#define TYPE_VALUE_BASE_H_

#include "type_value.h"
#include "type_pair.h"
#include "../operator.h"

#include <cassert>
#include <map>
#include <functional>

template <typename Derived>
struct TypeValueBase : TypeValue {

  static map<TypePair, function<TypeValue*(TypeValue*, TypeValue*)> > function_map;

  static AddOperatorFunction(TypePair type_pair, function<TypeValue*(TypeValue*, TypeValue*)> func) {
    Derived::function_map.insert({type_pair, func});
  }

  TypeValue* ExecuteOperator(Operator op, TypeValue *rhs) {
    TypePair key(op, this->type(), rhs->type());
    assert(function_map.count(key) != 0);
    auto func = function_map[key];
    return func(this, rhs);
  }

  Type type() override {
    return Derived::_type();
  }

};

#endif