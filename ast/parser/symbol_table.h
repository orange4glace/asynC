#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "symbol_table_entry.h"
#include "../identifier.h"
#include "../type/type_value.h"

#include <map>
#include <cassert>

struct SymbolTable {

  SymbolTable *parent;
  map<IdentifierNode*, TypeValue*> table;

  inline SymbolTable() {
    parent = nullptr;
  }
  
  inline AddSymbol(IdentifierNode *id, TypeValue *tv) {
    TypeValue *type_value = GetSymbol(id);
    assert(!type_value);
    table[id] = tv;
  }

  inline TypeValue* GetSymbol(IdentifierNode *identifier) {
    if (table.count(identifier)) return table[identifier];
    if (parent == nullptr) return nullptr;
    return parent->GetSymbol(identifier);
  }

};

#endif