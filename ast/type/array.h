#ifndef ARRAY_H_
#define ARRAY_H_

#include "ast/type/type_value_base.h"
#include "ast/identifier.h"
#include "ast/type/pointer.h"

#include <vector>

struct Array : TypeValueBase<Array> {

  int size;
  Identifier *identifier;
  TypeValue *element_type_value;

  inline Array(TypeValue *el, int size)
    : element_type_value(el), size(size) {
  }

  inline static void __Initialize() {
    Array::AddOperatorFunction(
      TypePair(Operator::SUBSCRIPT, Array::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue *r) -> TypeValue* {
        Array* lhs = static_cast<Array*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        TypeValue *element = lhs->element_type_value->Clone();
        element->refffffff = true;

        // Code generation
        symbol_table->AppendInstruction("ssss", "mov", "ecx", lhs->GetAddress(), "# get subscript base address");
        symbol_table->AppendInstruction("sss", "mov", "edx", rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ssd", "mul", "edx", lhs->element_type_value->size);
        symbol_table->AppendInstruction("ssss", "sub", "ecx", "edx", "# add subscript offset");
        symbol_table->AppendInstruction("sss", "push", "ecx", "# subscript element");
        element->local_symbol_table = symbol_table;
        element->stack_frame_offset = ++symbol_table->stack_frame_size;

        return element;
      }
    );

    Array::AddOperatorFunction(
      TypePair(Operator::CAST, Array::_type(), Pointer::_type()),
      [](TypeValue* l, TypeValue *r) -> TypeValue* {
        Array* lhs = static_cast<Array*>(l);

        TypeValue *element = lhs->element_type_value->Clone();
        Pointer *pointer = new Pointer(element);

        symbol_table->PushStackFrameBack(pointer);

        // Code generation
        symbol_table->AppendInstruction("ssss", "mov", pointer->GetIndirectAddress(), lhs->GetAddress(), "# array -> pointer");

        return pointer;
      }
    );
  }

  TypeValue* Clone() override {
    assert(false);
    return nullptr;
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