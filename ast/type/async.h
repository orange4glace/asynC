#ifndef ASYNC_H_
#define ASYNC_H_

#include "ast/type/type_value_base.h"
#include "ast/identifier.h"
#include "ast/type/function_parameter.h"

#include <vector>

struct Async : TypeValueBase<Async> {

  vector<TypeValue*> variable_capture_list;

  inline Async() {
    size = 2;
  }

  TypeValue* Clone() override {
    return new Async();
  }

  inline static void __Initialize() {
    Async::AddOperatorFunction(
      TypePair(Operator::ASSIGNMENT, Async::_type(), Async::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Async* lhs = static_cast<Async*>(l);
        Async* rhs = static_cast<Async*>(r);

        // Code generation
        symbol_table->AppendCode("s", "# async assignment");
        symbol_table->AppendInstruction("sss",
            "mov", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "mov", lhs->GetIndirectAddress(1), rhs->GetIndirectAddress(1));

        return lhs;
      }
    );
  }

  void PushStackFrameBack(SymbolTable *symbol_table) override;

  void Print(std::ostream& str) const override {
    indent();
    str << "[Async]\n";
    ii();
    di();
  }

  static inline Type _type() {
    return Type::ASYNC;
  }

};

#endif