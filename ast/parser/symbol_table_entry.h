#ifndef SYMBOL_TABLE_ENTRY_H_
#define SYMBOL_TABLE_ENTRY_H_

#include "../type_specifier.h"

struct SymbolTableEntry {

  TypeSpecifierNode *type_specifier;
  IdentifierNode *identifier;
  void* value;

  SymbolTableEntry(TypeSpecifierNode *ts, IdentifierNode *id) {
    type_specifier = ts;
    identifier = id;
  }

};

#endif