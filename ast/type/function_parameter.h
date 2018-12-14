#ifndef FUNCTION_PARAMETER_H_
#define FUNCTION_PARAMETER_H_

#include "ast/type/identifier.h"
#include "ast/type/type_value.h"

struct FunctionParameter {

  Identifier *identifier;
  TypeValue *type_value;

  FunctionParameter(Identifier *id, TypeValue *tv) :
      identifier(id), type_value(tv) {}

};

#endif