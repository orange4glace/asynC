#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "ast/type/type_value.h"

struct Function : TypeValue {

  TypeValue* return_type_value;

};

#endif