#include "ast/parser/symbol_table.h"
#include "ast/type/type_value.h"
#include "ast/type/integer.h"
#include "ast/type/void.h"
#include "ast/type/array.h"
#include "ast/type/pointer.h"
#include "ast/type/async.h"

const char* TypeValue::GetIndirectAddress(int offset) {
  int off = symbol_table->GetTypeValueOffset(this);
  if (refffffff) {
    if (offset) {
      string* c = new string(
        off == 0 ? "" : std::to_string(off) + "(ebp)");
      symbol_table->AppendInstruction("sss", "mov", "esi", c->c_str());
      symbol_table->AppendInstruction("ssd", "add", "esi", -offset);
      symbol_table->AppendInstruction("ss", "push", "esi");
      int res_off = -(++symbol_table->stack_frame_size);
      string* d = new string(
        off == 0 ? "" : std::to_string(res_off) + "{ebp}");
      return d->c_str();
    }
    string* c = new string(
      off == 0 ? "" : std::to_string(off) + "{ebp}");
    return c->c_str();
  }
  off -= offset;
  string* c = new string(
    off == 0 ? "" : std::to_string(off) + "(ebp)");
  return c->c_str();
}

const char* TypeValue::GetAddress() {
  int off = symbol_table->GetTypeValueOffset(this);
  symbol_table->AppendInstruction("sss", "mem", "esi", "ebp");
  symbol_table->AppendInstruction("ssd", "add", "esi", off);
  symbol_table->AppendInstruction("ss", "push", "esi");
  int res_off = -(++symbol_table->stack_frame_size);
  string* c = new string(
    res_off == 0 ? "" : std::to_string(res_off) + "(ebp)");
  return c->c_str();
}

void TypeValue::PushStackFrameBack(SymbolTable *symbol_table) {
  symbol_table->AppendInstruction("sdss", "push", 0, "# ", TypeToString(type()).c_str());
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = ++symbol_table->stack_frame_size;
}

void Async::PushStackFrameBack(SymbolTable *symbol_table) {
  symbol_table->AppendInstruction("sdss", "push", 0, "# ", TypeToString(type()).c_str());
  symbol_table->AppendInstruction("sd", "push", 0);
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = ++symbol_table->stack_frame_size;
  ++symbol_table->stack_frame_size;
}

void Array::PushStackFrameBack(SymbolTable *symbol_table) {
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = symbol_table->stack_frame_size + 1;
  symbol_table->AppendCode("sd", "# start array size", size);
  for (int i = 0; i < this->size; i ++) {
    for (int j = 0; j < element_type_value->size; j ++) {
      symbol_table->AppendInstruction("sd", "push", 0);
      symbol_table->stack_frame_size++;
    }
  }
}

void Pointer::PushStackFrameBack(SymbolTable *symbol_table) {
  if (created_by_new) {
    symbol_table->AppendInstruction("sss", "push", "eax", "# Pointer created by _new_");
    this->local_symbol_table = symbol_table;
    this->stack_frame_offset = ++symbol_table->stack_frame_size;
  }
  else {
    TypeValue::PushStackFrameBack(symbol_table);
  }
}