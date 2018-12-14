#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "ast/type/type_value_base.h"
#include "ast/type/function_parameter.h"

#include <vector>

struct Function : TypeValueBase<Function> {

  TypeValue* return_type_value;
  vector<FunctionParameter*> parameters;

  void Print(std::ostream& str) const override {
    indent();
    str << "[Function]\n";
    ii();
    return_type_value->Print(str);
    di();
  }

  static inline Type _type() {
    return Type::FUNCTION;
  }

};

#endif