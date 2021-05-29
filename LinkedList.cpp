#include "LinkedList.h"

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  quantityOfNodes = 0;
}

int LinkedList::header() { return head->element; }

int LinkedList::trailer() { return tail->element; }

int LinkedList::nOfNodes() { return quantityOfNodes; }