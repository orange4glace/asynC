#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "ast/identifier.h"
#include "ast/type/type_value.h"

#include <map>
#include <cassert>

struct TableCompare {
  inline bool operator()(IdentifierNode* const& lhs, IdentifierNode* const& rhs) const {
    return lhs->id.compare(rhs->id);
  }
};

struct SymbolTable {

  SymbolTable *parent;
  map<IdentifierNode*, TypeValue*, TableCompare> table;

  inline SymbolTable() {
    parent = nullptr;
  }
  
  inline AddSymbol(IdentifierNode *id, TypeValue *tv) {
    assert(!HasSymbol(id));
    table[id] = tv;
  }

  inline bool HasSymbol(IdentifierNode *identifier) {
    if (table.count(identifier)) return true;
    if (parent == nullptr) return false;
    return parent->HasSymbol(identifier);
  }

  inline TypeValue* GetSymbol(IdentifierNode *identifier) {
    if (table.count(identifier)) return table[identifier];
    assert(parent != nullptr);
    return parent->GetSymbol(identifier);
  }

};

#endif