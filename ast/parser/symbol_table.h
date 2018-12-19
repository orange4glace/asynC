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
extern SymbolTable *root_symbol_table;

struct TableCompare {
  inline bool operator()(Identifier* const& lhs, Identifier* const& rhs) const {
    return lhs->id.compare(rhs->id) < 0;
  }
};

struct SymbolTable {

  string name;
  int id;
  SymbolTable *parent;
  map<Identifier*, SymbolTableEntry*, TableCompare> table;
  vector<string> code;
  int instruction_size;

  int stack_frame_size;

  inline SymbolTable(string name) {
    parent = nullptr;
    this->name = name;
    stack_frame_size = 0;
    this->id = global_id++;
    instruction_size = 0;
  }

  inline SymbolTable(string name, SymbolTable *p) : SymbolTable(name) {
    parent = p;
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

  inline SymbolTable* GetLocalSymbolTable(Identifier *identifier) {
    if (table.count(identifier)) return this;
    assert(parent != nullptr);
    return parent->GetLocalSymbolTable(identifier);
  }

  inline void PushStackFrameBack(TypeValue* type_value) {
    if (type_value->local_symbol_table) {
      symbol_table->AppendInstruction("ss", "push", type_value->GetIndirectAddress());
      ++symbol_table->stack_frame_size;
    }
    else type_value->PushStackFrameBack(this);
  }

  inline int PushStackFrameBack() {
    AppendInstruction("sd", "push", 0);
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

  inline int GetTypeValueAddress(TypeValue *type_value) {
    if (type_value->local_symbol_table == this) return -type_value->stack_frame_offset;
    return parent->GetTypeValueOffset(type_value) + parent->stack_frame_size + (1 /* push ebp */ );
  }

  inline SymbolTable* Push(string name = "") {
    SymbolTable *next = new SymbolTable(name, this);
    symbol_table = next;
    return symbol_table;
  }

  inline void Pop() {
    for (auto& code : this->code)
      this->parent->code.emplace_back(code);
    this->parent->instruction_size += instruction_size;
    symbol_table = this->parent;
  }

  inline void SaveBasePointer() {
    symbol_table->AppendInstruction("sssd", "push", "ebp", "# save base pointer", id);
    symbol_table->AppendInstruction("sss", "mov", "ebp", "esp");
  }

  inline void RestoreBasePointer() {
    symbol_table->AppendInstruction("sssd", "pop", "ebp", "# restore base pointer", symbol_table->parent->id);
  }

  inline void FunctionReturn() {
    ClearStackFrame();
    symbol_table->AppendInstruction("ss", "pop", "ebp");
    symbol_table->AppendInstruction("s", "ret");
  }

  inline void ClearStackFrame() {
    symbol_table->AppendInstruction("ssd", "add", "esp", stack_frame_size * 4);
  }

  inline void Malloc() {
    symbol_table->AppendInstruction("s", "malloc");
  }

  inline void AppendInstruction(const char* fmt...) {
    va_list args;
    va_start(args, fmt);
    __AppendCode(fmt, args);
    va_end(args);
    ++instruction_size;
  }

  inline void AppendLabel(const char* fmt...) {
    va_list args;
    va_start(args, fmt);
    __AppendCode(fmt, args);
    va_end(args);
  }

  inline void AppendCode(const char* fmt...) {
    va_list args;
    va_start(args, fmt);
    __AppendCode(fmt, args);
    va_end(args);
  }

  inline void __AppendCode(const char* fmt, va_list args) {
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
  }

  inline void PrintCode() {
    for (auto x : code)
      if (x == "\n") cout << "\n";
      else cout << x << " ";
  }

};

#endif