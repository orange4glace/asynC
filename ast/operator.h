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
  INCREMENT,
  DECREMENT,
  POSTFIX_INCREMENT,
  POSTFIX_DECREMENT,
  LEFT_SHIFT,
  RIGHT_SHIFT,
  EQUAL,
  NOT_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,
};

inline extern std::string OperatorToString(Operator op) {
  switch (op) {
  case Operator::ASSIGNMENT: return "ASSIGNMENT";
  case Operator::ADDITION: return "ADDITION";
  case Operator::SUBTRACTION: return "SUBTRACTION";
  case Operator::MULTIPLICATION: return "MULTIPLICATION";
  case Operator::DIVISION: return "DIVISION";
  case Operator::MODULAR: return "MODULAR";
  case Operator::INCREMENT: return "INCREMENT";
  case Operator::DECREMENT: return "DECREMENT";
  case Operator::POSTFIX_INCREMENT: return "POSTFIX_INCREMENT";
  case Operator::POSTFIX_DECREMENT: return "POSTFIX_DECREMENT";
  case Operator::LEFT_SHIFT: return "LEFT_SHIFT";
  case Operator::RIGHT_SHIFT: return "RIGHT_SHIFT";
  case Operator::EQUAL: return "EQUAL";
  case Operator::NOT_EQUAL: return "NOT_EQUAL";
  case Operator::GREATER: return "GREATER";
  case Operator::GREATER_EQUAL: return "GREATER_EQUAL";
  case Operator::LESS: return "LESS";
  case Operator::LESS_EQUAL: return "LESS_EQUAL";
  default: return "UNKNOWN";
  }
}

#endif