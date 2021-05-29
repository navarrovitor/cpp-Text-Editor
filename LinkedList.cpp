#include "LinkedList.h"
#include <string>

LinkedList::LinkedList()
{
  head = tail = NULL;
  size = 0;
}

void LinkedList::addFront(Data data)
{
  Node *node = new Node(data);
  if (head != NULL)
    head->prev = node;
  node->next = head;
  node->prev = NULL;
  head = node;
  if (tail == NULL)
    tail = node;
  size++;
}

void LinkedList::addBack(Data data)
{
  if (head == NULL)
    return addFront(data);
  Node *node = new Node(data);
  tail->next = node;
  node->prev = tail;
  tail = node;
  size++;
}

void LinkedList::addInPosition(Data data, int position)
{
  Node *node = new Node(data), *aux;
  if (position < 1)
    return;
  if (position > size + 1)
    return;
  if (position == 1)
  {
    addFront(data);
    return;
  }
  if (position == size + 1)
  {
    addBack(data);
    return;
  }
  if (position <= size / 2)
  {
    aux = head;
    for (int i = 1; i < position; i++)
      aux = aux->next;
  }
  else
  {
    aux = tail;
    for (int i = size; i > position; i--)
      aux = aux->prev;
  }
  node->next = aux;
  node->prev = aux->prev;
  aux->prev->next = node;
  aux->prev = node;
  size++;
}

void LinkedList::removeFront()
{
  if (head == NULL)
    return;
  if (head->next == NULL)
    head = tail = NULL;
  else
  {
    head = head->next;
    head->prev = NULL;
  }
  size--;
}

void LinkedList::removeBack()
{
  if (head == NULL)
    return;
  if (head->next == NULL)
    head = tail = NULL;
  else
  {
    tail = tail->prev;
    tail->next = NULL;
  }
  size--;
}

void LinkedList::removeInPosition(int position)
{
  Node *node, *aux;
  if (head == NULL)
  {
    return;
  }
  if (position < 1)
  {
    return;
  }
  if (position > size + 1)
  {
    return;
  }
  if (position == 1)
  {
    removeFront();
    return;
  }
  if (position == size)
  {
    removeBack();
    return;
  }
  if (position <= size / 2)
  {
    node = head;
    for (int i = 0; i < position - 2; i++)
      node = node->next;
    aux = node->next->next;
    aux->prev = node;
    node->next = aux;
  }
  else
  {
    node = tail;
    for (int i = size; i > position + 1; i--)
      node = node->prev;
    aux = node->prev->prev;
    aux->next = node;
    node->prev = aux;
  }
  size--;
  return;
}

void LinkedList::print()
{
  Node *aux = head;
  cout << "[";
  while (aux != NULL)
  {
    if (aux->next == NULL)
    {
      cout << aux->data;
      break;
    }
    cout << aux->data << ", ";
    aux = aux->next;
  }
  cout << "]" << endl;
}

bool stopChar(char character)
{
  char stopCharacter[] = {'.', ',', ' '};
  for (int i = 0; i < 3; i++)
  {
    if (character == stopCharacter[i])
      return true;
  }
  return false;
}

int LinkedList::countWord(string word)
{
  int countC = 0, countW = 0;
  char character;
  for (Node *node = head; node != NULL; node = node->next)
  {
    character = node->data;
    if (stopChar(character))
    {
      if (countC == word.size())
        countW++;
      countC = 0;
    }
    else
    {
      if (character == word[countC])
        countC++;
    }
  }
  return countW;
}

void LinkedList::changeWord(string oldWord, string newWord)
{
  int countC = 0, position = 1, aux;
  char character;
  for (Node *node = head; node != NULL; node = node->next, position++)
  {
    character = node->data;
    if (stopChar(character))
    {
      if (countC == oldWord.size())
      {
        aux = position - countC;
        for (int i = 0; i < countC; i++)
          removeInPosition(aux);
        for (int i = 0; i < newWord.size(); i++, aux++)
          addInPosition(newWord[i], aux);
        position = aux;
        countC++;
      }
      countC = 0;
    }
    else
    {
      if (character == oldWord[countC])
        countC++;
    }
  }
}