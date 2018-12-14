#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "ast/type/identifier.h"
#include "ast/type/type_value.h"

#include <map>
#include <cassert>

struct TableCompare {
  inline bool operator()(Identifier* const& lhs, Identifier* const& rhs) const {
    return lhs->id.compare(rhs->id);
  }
};

struct SymbolTable {

  SymbolTable *parent;
  map<Identifier*, TypeValue*, TableCompare> table;

  inline SymbolTable() {
    parent = nullptr;
  }

  inline SymbolTable(SymbolTable *p) {
    parent = p;
  }
  
  inline AddSymbol(Identifier *id, TypeValue *tv) {
    assert(!HasSymbol(id));
    table[id] = tv;
  }

  inline bool HasSymbol(Identifier *identifier) {
    if (table.count(identifier)) return true;
    if (parent == nullptr) return false;
    return parent->HasSymbol(identifier);
  }

  inline TypeValue* GetSymbol(Identifier *identifier) {
    if (table.count(identifier)) return table[identifier];
    assert(parent != nullptr);
    return parent->GetSymbol(identifier);
  }

};

#endif