#include "LinkedList.h"

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  quantityOfNodes = 0;
}

bool LinkedList::empty() { return head == NULL; }

int LinkedList::header() { return empty() ? -1 : head->element; }

int LinkedList::trailer() { return empty() ? -1 : tail->element; }

int LinkedList::nOfNodes() { return quantityOfNodes; }