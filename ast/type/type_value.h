#ifndef TYPE_VALUE_H_
#define TYPE_VALUE_H_

#include <iostream>
#include <string>

#include "ast/type/type.h"
#include "../operator.h"

using namespace std;

struct SymbolTable;

#define DIRECT_ADDRESSING 0
#define INDEX_ADDRESSING 1

struct Pointer;

struct TypeValue {

  bool referenced;
  Pointer* referrer;

  bool lvalue;
  int stack_frame_offset;
  SymbolTable *local_symbol_table;

  int addressing_mode;
  TypeValue *index_base;
  TypeValue *index_offset;

  inline TypeValue() : local_symbol_table(nullptr) {
    referenced = false;
    addressing_mode = DIRECT_ADDRESSING;
    index_base = index_offset = nullptr;
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

  const char* GetStackFrameAddress();
  virtual void PushStackFrameBack(SymbolTable *symbol_table);

};

#endif