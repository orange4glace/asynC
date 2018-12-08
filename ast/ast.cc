#include "ast.h"
#include <iostream>

int indent_count = 0;
void indent() {
  for (int i = 0; i < indent_count; i ++)
  std::cout << "  ";
}
void ii() { indent_count++; }
void di() { indent_count--; }