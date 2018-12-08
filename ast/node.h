#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>

using namespace std;

struct Node {
  virtual void Print() = 0;
};

#endif