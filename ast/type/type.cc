#include "ast/parser/symbol_table.h"
#include "ast/type/type_value.h"
#include "ast/type/integer.h"
#include "ast/type/void.h"
#include "ast/type/array.h"

const char* TypeValue::GetStackFrameAddress() {
  int off = symbol_table->GetTypeValueOffset(this);
  string* c = new string(
    off == 0 ? "" : std::to_string(off) + "(ebp)");
  return c->c_str();
}

void Integer::PushStackFrameBack(SymbolTable *symbol_table) {
  symbol_table->AppendCode("sd", "push", this->value);
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = ++symbol_table->stack_frame_size;
}

void Void::PushStackFrameBack(SymbolTable *symbol_table) {
  symbol_table->AppendCode("sd", "push", 0);
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = ++symbol_table->stack_frame_size;
}

void Array::PushStackFrameBack(SymbolTable *symbol_table) {
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = symbol_table->stack_frame_size + 1;
  for (int i = 0; i < this->size; i ++) {
    symbol_table->AppendCode("sd", "push", 0);
    symbol_table->stack_frame_size++;
  }
}