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

  inline static void __Initialize() {
    Integer::AddOperatorFunction(
      TypePair(Operator::ASSIGNMENT, Integer::_type(), Integer::_type()),
      [](TypeValue* l, TypeValue* r) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);
        Integer* rhs = static_cast<Integer*>(r);
        lhs->value = rhs->value;

        // Code generation
        symbol_table->AppendInstruction("sss",
            "mov", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "add", res->GetIndirectAddress(), r->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "sub", res->GetIndirectAddress(), r->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "mul", res->GetIndirectAddress(), r->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "div", res->GetIndirectAddress(), r->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("sss",
            "mod", res->GetIndirectAddress(), r->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "sete", res->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "setne", res->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "setg", res->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "setge", res->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "setl", res->GetIndirectAddress());

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
        symbol_table->AppendInstruction("sss",
            "cmp", lhs->GetIndirectAddress(), rhs->GetIndirectAddress());
        symbol_table->AppendInstruction("ss",
            "setle", res->GetIndirectAddress());

        return res;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::INCREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        // Code generation
        symbol_table->AppendInstruction("ssd",
            "add", l->GetIndirectAddress(), 1);

        return lhs;
      }
    );
    Integer::AddOperatorFunction(
      TypeSingle(Operator::DECREMENT, Integer::_type()),
      [](TypeValue* l) -> TypeValue* {
        Integer* lhs = static_cast<Integer*>(l);

        // Code generation
        symbol_table->AppendInstruction("ssd",
            "sub", l->GetIndirectAddress(), 1);

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("ssd",
            "add", l->GetIndirectAddress(), 1);

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
        symbol_table->AppendInstruction("sss",
            "mov", res->GetIndirectAddress(), l->GetIndirectAddress());
        symbol_table->AppendInstruction("ssd",
            "sub", l->GetIndirectAddress(), 1);

        return res;
      }
    );
  }
  
  void Print(std::ostream& str) const override {
    indent();
    str << "[Integer] " << value << "\n";
  }

  static inline Type _type() {
    return Type::INTEGER;
  }

};

#endif