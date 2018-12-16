#ifndef TYPE_VALUE_FACTORY_H_
#define TYPE_VALUE_FACTORY_H_

#include "type_value.h"
#include "type.h"
#include "integer.h"
#include "void.h"
#include "array.h"

struct TypeValueFactory {

  static TypeValue* Create(Type type) {
    switch (type) {
    case Type::INTEGER:
      return new Integer();
    case Type::VOID:
      return new Void();
    }
    return nullptr;
  }

};

#endif 