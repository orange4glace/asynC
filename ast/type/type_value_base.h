#ifndef TYPE_VALUE_BASE_H_
#define TYPE_VALUE_BASE_H_

#include "type_value.h"
#include "type_single.h"
#include "type_pair.h"
#include "../operator.h"

#include <cassert>
#include <map>
#include <functional>

template <typename Derived>
struct TypeValueBase : TypeValue {

  static map<TypePair, function<TypeValue*(TypeValue*, TypeValue*)> > binary_operator_map;
  static map<TypeSingle, function<TypeValue*(TypeValue*)> > unary_operator_map;

  static AddOperatorFunction(TypePair type_pair, function<TypeValue*(TypeValue*, TypeValue*)> func) {
    Derived::binary_operator_map.insert({type_pair, func});
  }

  static AddOperatorFunction(TypeSingle type_single, function<TypeValue*(TypeValue*)> func) {
    Derived::unary_operator_map.insert({type_single, func});
  }

  TypeValue* ExecuteOperator(Operator op, TypeValue *rhs) override {
    cout << "exe op " << OperatorToString(op) << " " << TypeToString(type()) << " " << TypeToString(rhs->type()) << endl;
    TypePair key(op, this->type(), rhs->type());
    assert(Derived::binary_operator_map.count(key) != 0);
    auto func = Derived::binary_operator_map[key];
    return func(this, rhs);
  }

  TypeValue* ExecuteOperator(Operator op) override {
    TypeSingle key(op, this->type());
    assert(Derived::unary_operator_map.count(key) != 0);
    auto func = Derived::unary_operator_map[key];
    return func(this);
  }

  Type type() override {
    return Derived::_type();
  }

};

template <typename Derived>
map<TypePair, function<TypeValue*(TypeValue*, TypeValue*)> > TypeValueBase<Derived>::binary_operator_map;
template <typename Derived>
map<TypeSingle, function<TypeValue*(TypeValue*)> > TypeValueBase<Derived>::unary_operator_map;

#endif