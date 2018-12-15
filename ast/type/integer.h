#ifndef INTEGER_H_
#define INTEGER_H_

#include "type_value_base.h"
#include "ast/parser/symbol_table.h"

struct Integer : TypeValueBase<Integer> {
  int value;

  inline static void Initialize() {
    Integer::AddOperatorFunction(
      TypePair(Operator::ADDITION, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("sss",
            "add", res->GetStackFrameAddress(), r->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::SUBTRACTION, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("sss",
            "sub", res->GetStackFrameAddress(), r->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::ASSIGNMENT, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);
        lhs->value = rhs->value;

        // Code generation
        symbol_table->AppendCode("sss",
            "mov", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());

        return lhs;
      }
    );
  }

  void PushStackFrameBack(SymbolTable *symbol_table) override;

  void Print(std::ostream& str) const override {
    indent();
    str << "[Integer] " << value << "\n";
  }

  static inline Type _type() {
    return Type::INTEGER;
  }

};

#endif