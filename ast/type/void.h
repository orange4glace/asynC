#ifndef VOID_H_
#define VOID_H_

#include "type_value_base.h"
#include "ast/parser/symbol_table.h"

struct Void : TypeValueBase<Void> {

  TypeValue* Clone() override {
    Void *type_value = new Void();
    return type_value;
  }

  inline static void Initialize() {}

  void PushStackFrameBack(SymbolTable *symbol_table) override;

  void Print(std::ostream& str) const override {
    indent();
    str << "[Void]\n";
  }

  static inline Type _type() {
    return Type::VOID;
  }

};

#endif