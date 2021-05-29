#include "LinkedList.h"

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  quantityOfNodes = 0;
}

bool stopCharacter(char character)
{
  char stopChar[] = {'.', ',', ' '};
  for (int i = 0; i < 3; i++)
  {
    if (character == stopChar[i])
      return true;
  }
  return false;
}

bool LinkedList::empty() { return head == NULL; }

int LinkedList::header() { return empty() ? -1 : head->getElement(); }

int LinkedList::trailer() { return empty() ? -1 : tail->getElement(); }

int LinkedList::nOfNodes() { return quantityOfNodes; }

void LinkedList::printList()
{
  cout << "[ ";
  for (Node *indicator = head; indicator != NULL; indicator = indicator->getNext())
  {
    if (indicator->getNext() == NULL)
    {
      cout << indicator->getElement();
      break;
    }
    cout << indicator->getElement() << ", ";
  }
  cout << " ]" << endl;
}

void LinkedList::insertAtHead(char element)
{
  Node *newNode = new Node(element);
  if (!empty())
    head->setPrev(newNode);
  newNode->setNext(head);
  newNode->setPrev(NULL);
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
  tail->setNext(newNode);
  newNode->setPrev(tail);
  tail = newNode;
  quantityOfNodes++;
}

int LinkedList::insertAtPosition(int position, char element)
{
  int limit = nOfNodes() + 1, half = nOfNodes() / 2, size = nOfNodes();
  if (position < 1 || position > limit)
    return -1;
  if (position == 1)
  {
    insertAtHead(element);
    return 1;
  }
  if (position == limit)
  {
    insertAtTail(element);
    return position;
  }
  Node *newNode = new Node(element), *indicator;
  if (position <= half)
  {
    indicator = head;
    for (int j = 1; j < position; j++)
      indicator = indicator->getNext();
  }
  else
  {
    indicator = tail;
    for (int j = size; j > position; j--)
      indicator = indicator->getPrev();
  }
  newNode->setNext(indicator);
  newNode->setPrev(indicator->getPrev());
  indicator->getPrev()->setNext(newNode);
  indicator->setPrev(newNode);
  quantityOfNodes++;
  return position;
}