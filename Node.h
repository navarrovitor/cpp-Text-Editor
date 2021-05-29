#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string.h>

using namespace std;

class Node
{
private:
  Node *prev;
  Node *next;
  char element;

  // friend class LinkedList;

public:
  Node(char);

  char getElement();
  Node *getPrev();
  Node *getNext();

  void setElement(char);
  void setPrev(Node *);
  void setNext(Node *);
};
#endif
