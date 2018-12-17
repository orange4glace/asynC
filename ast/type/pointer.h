#ifndef POINTER_H_
#define POINTER_H_

#include "ast/type/type_value_base.h"
#include "ast/identifier.h"

#include <vector>

struct Pointer : TypeValueBase<Pointer> {

  bool created_by_new;

  Identifier *identifier;
  TypeValue *content_type_value;

  inline Pointer(TypeValue *el)
    : content_type_value(el) {
    created_by_new = false;
    content_type_value->referenced = true;
    content_type_value->referrer = this;
  }

  inline static void Initialize() {
    Pointer::AddOperatorFunction(
      TypePair(Operator::ASSIGNMENT, Pointer::_type(), Pointer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Pointer* lhs = static_cast<Pointer*>(l);
        Pointer* rhs = static_cast<Pointer*>(r);

        // Code generation
        symbol_table->AppendCode("sss",
            "mov", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());

        return lhs;
      }
    );
  }

  TypeValue* Clone() override {
    return new Pointer(content_type_value);
  }

  inline bool CheckType(TypeValue *rhs) override {
    if (type() != rhs->type()) return false;
    Pointer *rhs_pointer = static_cast<Pointer*>(rhs);
    return content_type_value->CheckType(rhs_pointer->content_type_value);
  }

  void Print(std::ostream& str) const override {
    indent();
    str << "[Pointer]\n";
    ii();
    content_type_value->Print(str);
    di();
  }

  static inline Type _type() {
    return Type::POINTER;
  }

  void PushStackFrameBack(SymbolTable *symbol_table) override;

};

#endif