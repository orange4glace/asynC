#ifndef TYPE_VALUE_H_
#define TYPE_VALUE_H_

#include <iostream>
#include <string>

#include "ast/type/type.h"
#include "../operator.h"

using namespace std;

struct SymbolTable;

struct TypeValue {

  bool refffffff;
  
  int size;
  bool lvalue;
  int stack_frame_offset;
  SymbolTable *local_symbol_table;

  inline TypeValue() : local_symbol_table(nullptr) {
    refffffff = false;
    size = 1;
  }

  virtual TypeValue* Clone() = 0;

  virtual TypeValue* ExecuteOperator(Operator op, TypeValue* rhs) = 0;
  virtual TypeValue* ExecuteOperator(Operator op) = 0;

  virtual inline bool CheckType(TypeValue *rhs) {
    return type() != rhs->type();
  }

  virtual Type type() = 0;

  virtual void Print(std::ostream& str) const = 0;
  inline friend std::ostream& operator<<(std::ostream& str, TypeValue const& self) {
    self.Print(str);
    return str;
  }

  const char* GetIndirectAddress(int offset = 0);
  const char* GetAddress();
  virtual void PushStackFrameBack(SymbolTable *symbol_table);

};

#endif