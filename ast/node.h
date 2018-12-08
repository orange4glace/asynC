#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>

using namespace std;

struct Visitor;

struct Node {
  virtual void Print() = 0;

  virtual void Accept(Visitor* visitor) = 0;
};

#endif