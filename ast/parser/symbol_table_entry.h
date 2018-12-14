/*
#ifndef SYMBOL_TABLE_ENTRY_H_
#define SYMBOL_TABLE_ENTRY_H_

#include "ast/type/identifier.h"
#include "ast/type_specifier.h"

struct SymbolTableEntry {

  TypeSpecifierNode *type_specifier;
  Identifier *identifier;
  void* value;

  SymbolTableEntry(TypeSpecifierNode *ts, Identifier *id) {
    type_specifier = ts;
    identifier = id;
  }

};

#endif
*/