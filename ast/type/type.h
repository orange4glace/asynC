#ifndef TYPE_H_
#define TYPE_H_

#include <string>

enum class Type : int {
  IDENTIFIER = 0x00,
  VOID,
  INTEGER,
  FLOAT,
  ASYNC,
  FUNCTION,
  ARRAY,
};

inline extern std::string TypeToString(Type type) {
  switch (type) {
  case Type::IDENTIFIER: return "IDENTIFIER";
  case Type::VOID: return "VOID";
  case Type::INTEGER: return "INTEGER";
  case Type::FLOAT: return "FLOAT";
  case Type::ASYNC: return "ASYNC";
  case Type::FUNCTION: return "FUNCTION";
  case Type::ARRAY: return "ARRAY";
  default: return "UNKNOWN";
  }
}

#endif