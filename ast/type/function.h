#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "ast/type/type_value.h"
#include "ast/type/function_parameter.h"

#include <vector>

struct Function : TypeValue {

  TypeValue* return_type_value;
  vector<FunctionParameter*> parameters;

};

#endif