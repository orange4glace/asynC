#ifndef ARRAY_H_
#define ARRAY_H_

#include "ast/type/type_value_base.h"
#include "ast/identifier.h"

#include <vector>

struct Array : TypeValueBase<Array> {

  int size;
  Identifier *identifier;
  TypeValue *element_type_value;

  inline Array(TypeValue *el, int size)
    : element_type_value(el), size(size) {
  }

  TypeValue* Clone() override {
    assert(false);
    return nullptr;
  }

  inline TypeValue *GetTypeValueAt(int index) {
    TypeValue *element = element_type_value->Clone();
    element->local_symbol_table = this->local_symbol_table;
    element->stack_frame_offset = this->stack_frame_offset + index;
    return element;
  }

  void PushStackFrameBack(SymbolTable *symbol_table) override;

  void Print(std::ostream& str) const override {
    indent();
    str << "[Array] " << size << "\n";
    ii();
    element_type_value->Print(str);
    di();
  }

  static inline Type _type() {
    return Type::ARRAY;
  }

};

#endif