#ifndef SYMBOL_TABLE_ENTRY_H_
#define SYMBOL_TABLE_ENTRY_H_

#include "ast/type/type_value.h"

struct SymbolTableEntry {

  TypeValue *type_value;
  int offset;

  inline SymbolTableEntry(TypeValue *tv) {
    type_value = tv;
  }

};

#endif