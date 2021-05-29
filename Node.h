#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string.h>

using namespace std;

class Node
{
private:
  Node *prev, *next;
  char element;

  friend class LinkedList;

public:
  Node(char d);
};
#endif
