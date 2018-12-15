#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "ast/parser/symbol_table_entry.h"
#include "ast/type/identifier.h"
#include "ast/type/type_value.h"

#include <map>
#include <cassert>
#include <vector>
#include <string>
#include <cstdarg>

using namespace std;

struct SymbolTable;
extern SymbolTable *symbol_table;

struct TableCompare {
  inline bool operator()(Identifier* const& lhs, Identifier* const& rhs) const {
    return lhs->id.compare(rhs->id) < 0;
  }
};

struct SymbolTable {

  SymbolTable *parent;
  map<Identifier*, SymbolTableEntry*, TableCompare> table;
  vector<string> code;

  int stack_frame_size;

  inline SymbolTable() {
    parent = nullptr;
    stack_frame_size = 0;
  }

  inline SymbolTable(SymbolTable *p) {
    parent = p;
    stack_frame_size = 0;
  }
  
  inline void AddSymbol(Identifier *id, TypeValue *tv) {
    assert(!HasSymbol(id));
    table[id] = new SymbolTableEntry(tv);
  }

  inline bool HasSymbol(Identifier *identifier) {
    if (table.count(identifier)) return true;
    if (parent == nullptr) return false;
    return parent->HasSymbol(identifier);
  }

  inline TypeValue* GetSymbol(Identifier *identifier) {
    if (table.count(identifier)) return table[identifier]->type_value;
    assert(parent != nullptr);
    return parent->GetSymbol(identifier);
  }

  inline void PushStackFrameBack(TypeValue* type_value) {
    type_value->PushStackFrameBack(this);
  }

  inline int PushStackFrameBack() {
    AppendCode("sd", "push", 0);
    return ++stack_frame_size;
  }

  inline int GetSymbolOffset(Identifier *identifier) {
    assert(HasSymbol(identifier));
    if (table.count(identifier)) return -table[identifier]->type_value->stack_frame_offset;
    return parent->GetSymbolOffset(identifier) + parent->stack_frame_size;
  }

  inline int GetTypeValueOffset(TypeValue *type_value) {
    if (type_value->local_symbol_table == this) return -type_value->stack_frame_offset;
    return parent->GetTypeValueOffset(type_value) + parent->stack_frame_size + (1 /* push ebp */ );
  }

  inline void Push() {
    symbol_table->AppendCode("ss", "push", "ebp");
    symbol_table->AppendCode("sss", "mov", "ebp", "esp");
    SymbolTable *next = new SymbolTable(this);
    symbol_table = next;
  }

  inline void Pop() {
    symbol_table->AppendCode("ss", "pop", "ebp");
    for (auto& code : this->code)
      this->parent->code.emplace_back(code);
    symbol_table = this->parent;
  }

  inline void ClearStackFrame() {
    symbol_table->AppendCode("ssd", "add", "esp", symbol_table->stack_frame_size * 4);
  }

  inline void AppendCode(const char* fmt...) {
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            code.push_back(std::to_string(i));
        } else if (*fmt == 's') {
            char* s = va_arg(args, char*);
            code.push_back(string(s));
        } else if (*fmt == 'f') {
        }
        ++fmt;
    }

    code.push_back("\n");
    va_end(args);
  }

  inline void PrintCode() {
    for (auto x : code)
      if (x == "\n") cout << "\n";
      else cout << x << " ";
  }

};

#endif