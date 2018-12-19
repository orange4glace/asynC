#include "symbol_table.h"
#include "visitor.h"

SymbolTable *symbol_table = new SymbolTable("Root");
SymbolTable *root_symbol_table = symbol_table;
Visitor* visitor = new Visitor();