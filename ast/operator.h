#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <string>

enum class Operator : int {
  ASSIGNMENT        = 0x00,
  ADDITION,
  SUBTRACTION,
  MULTIPLICATION,
  DIVISION,
  MODULAR,
};

inline extern std::string OperatorToString(Operator op) {
  switch (op) {
  case Operator::ASSIGNMENT: return "ASSIGNMENT";
  case Operator::ADDITION: return "ADDITION";
  case Operator::SUBTRACTION: return "SUBTRACTION";
  case Operator::MULTIPLICATION: return "MULTIPLICATION";
  case Operator::DIVISION: return "DIVISION";
  case Operator::MODULAR: return "MODULAR";
  default: return "UNKNOWN";
  }
}

#endif