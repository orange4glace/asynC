#include "symbol_table.h"
#include "visitor.h"

SymbolTable *symbol_table = new SymbolTable();
Visitor* visitor = new Visitor();