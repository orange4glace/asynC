#ifndef TYPE_VALUE_FACTORY_H_
#define TYPE_VALUE_FACTORY_H_

#include "type_value.h"
#include "type.h"
#include "integer.h"
#include "void.h"
#include "array.h"
#include "pointer.h"
#include "async.h"

struct TypeValueFactory {

  static TypeValue* Create(Type type) {
    switch (type) {
    case Type::INTEGER:
      return new Integer();
    case Type::VOID:
      return new Void();
    case Type::ASYNC:
      return new Async();
    }
    return nullptr;
  }

};

#endif 