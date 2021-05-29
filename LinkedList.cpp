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

int LinkedList::header() { return empty() ? -1 : head->element; }

int LinkedList::trailer() { return empty() ? -1 : tail->element; }

int LinkedList::nOfNodes() { return quantityOfNodes; }

void LinkedList::printList()
{
  cout << "[ ";
  for (Node *indicator = head; indicator != NULL; indicator = indicator->next)
  {
    if (indicator->next == NULL)
    {
      cout << indicator->element;
      break;
    }
    cout << indicator->element << ", ";
  }
  cout << " ]" << endl;
}

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
