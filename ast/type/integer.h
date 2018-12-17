#ifndef INTEGER_H_
#define INTEGER_H_

#include "type_value_base.h"
#include "ast/parser/symbol_table.h"

struct Integer : TypeValueBase<Integer> {
  int value;

  TypeValue* Clone() override {
    Integer *type_value = new Integer();
    type_value->value = this->value;
    return type_value;
  }

  inline static void Initialize() {
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
      TypePair(Operator::MULTIPLICATION, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("sss",
            "mul", res->GetStackFrameAddress(), r->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::DIVISION, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("sss",
            "div", res->GetStackFrameAddress(), r->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::MODULAR, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("sss",
            "mod", res->GetStackFrameAddress(), r->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::EQUAL, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "sete", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::NOT_EQUAL, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "setne", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::GREATER, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "setg", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::GREATER_EQUAL, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "setge", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::LESS, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "setl", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypePair(Operator::LESS_EQUAL, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);

        Integer* res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "cmp", lhs->GetStackFrameAddress(), rhs->GetStackFrameAddress());
        symbol_table->AppendCode("ss",
            "setle", res->GetStackFrameAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::INCREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        // Code generation
        symbol_table->AppendCode("ssd",
            "add", l->GetStackFrameAddress(), 1);

        return lhs;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::DECREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        // Code generation
        symbol_table->AppendCode("ssd",
            "sub", l->GetStackFrameAddress(), 1);

        return lhs;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::POSTFIX_INCREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        Integer *res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("ssd",
            "add", l->GetStackFrameAddress(), 1);

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::POSTFIX_DECREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        Integer *res = new Integer();
        // Code generation
        symbol_table->PushStackFrameBack(res);
        symbol_table->AppendCode("sss",
            "mov", res->GetStackFrameAddress(), l->GetStackFrameAddress());
        symbol_table->AppendCode("ssd",
            "sub", l->GetStackFrameAddress(), 1);

        return res;
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