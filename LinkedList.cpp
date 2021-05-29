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

void LinkedList::insertAtHead(char element)
{
  Node *newNode = new Node(element);
  if (!empty())
    head->prev = newNode;
  newNode->next = head;
  newNode->prev = NULL;
  head = newNode;
  if (tail == NULL)
    tail = newNode;
  quantityOfNodes++;
}

void LinkedList::insertAtTail(char element)
{
  if (empty())
    return this->insertAtHead(element);
  Node *newNode = new Node(element);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
  quantityOfNodes++;
}
