#include "ast/parser/symbol_table.h"
#include "ast/type/type_value.h"
#include "ast/type/integer.h"
#include "ast/type/void.h"
#include "ast/type/array.h"
#include "ast/type/pointer.h"

void TypeValue::PushStackFrameBack(SymbolTable *symbol_table) {
  symbol_table->AppendCode("sd", "push", 0);
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = ++symbol_table->stack_frame_size;
}

const char* TypeValue::GetStackFrameAddress() {
  if (referenced) {
    cout << "referenced" << endl;
    symbol_table->AppendCode("sss", "mov", "esi", referrer->GetStackFrameAddress());
    return "[esi]";
  }
  if (addressing_mode == DIRECT_ADDRESSING) {
    int off = symbol_table->GetTypeValueOffset(this);
    string* c = new string(
      off == 0 ? "" : std::to_string(off) + "(ebp)");
    return c->c_str();
  }
  else if (addressing_mode == INDEX_ADDRESSING) {
    // commit index register first
    symbol_table->AppendCode("ssd", "mov", "esi", symbol_table->GetTypeValueOffset(index_base));
    symbol_table->AppendCode("sss", "sub", "esi", index_offset->GetStackFrameAddress());
    return "esi(ebp)";
  }
}

void Array::PushStackFrameBack(SymbolTable *symbol_table) {
  this->local_symbol_table = symbol_table;
  this->stack_frame_offset = symbol_table->stack_frame_size + 1;
  for (int i = 0; i < this->size; i ++) {
    if (i == 0) symbol_table->AppendCode("sdsd", "push", 0, "# start array size", size);
    else symbol_table->AppendCode("sd", "push", 0);
    symbol_table->stack_frame_size++;
  }
}

void Pointer::PushStackFrameBack(SymbolTable *symbol_table) {
  if (created_by_new) {
    symbol_table->AppendCode("ss", "push", "eax");
    this->local_symbol_table = symbol_table;
    this->stack_frame_offset = ++symbol_table->stack_frame_size;
  }
  else {
    TypeValue::PushStackFrameBack(symbol_table);
  }
}