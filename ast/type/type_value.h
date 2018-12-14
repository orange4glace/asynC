#ifndef TYPE_VALUE_H_
#define TYPE_VALUE_H_

#include <iostream>
#include <string>

#include "ast/type/type.h"
#include "../operator.h"

using namespace std;

struct SymbolTable;

struct TypeValue {

  bool lvalue;
  int stack_frame_offset;
  SymbolTable *local_symbol_table;

  virtual TypeValue* ExecuteOperator(Operator op, TypeValue* rhs) = 0;

  virtual Type type() = 0;

  virtual void Print(std::ostream& str) const = 0;
  inline friend std::ostream& operator<<(std::ostream& str, TypeValue const& self) {
    self.Print(str);
    return str;
  }

  const char* GetStackFrameAddress();

};

#endif