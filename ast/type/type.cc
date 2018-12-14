#include "ast/parser/symbol_table.h"
#include "ast/type/type_value.h"

const char* TypeValue::GetStackFrameAddress() {
  int off = symbol_table->GetTypeValueOffset(this);
  string* c = new string("rsp" +
      (off == 0 ? ""
      :off > 0 ? "+" + std::to_string(off)
      :          "-" + std::to_string(off)));
  return c->c_str();
}