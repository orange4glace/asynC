#ifndef NODE_H_
#define NODE_H_

#include "ast.h"

#include <iostream>
#include <string>

using namespace std;

struct Visitor;

struct Node {
  Node* next;
  int id;

  Node() : next(nullptr) {
    id = global_id++;
  }

  virtual void Print() = 0;

  virtual void Accept(Visitor* visitor) = 0;
};

#endif