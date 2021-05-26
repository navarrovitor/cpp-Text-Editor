#include "LinkedList.h"
#include <string>

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

bool LinkedList::empty() { return head == NULL; }

int LinkedList::qty() { return size; }

Data LinkedList::frontValue() { return head->data; }

Data LinkedList::backValue() { return tail->data; }

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
  if (position < 1)
  {
    cout << "A posição tem de ser maior ou igual a 1" << endl;
    return;
  }
  if (position > size + 1)
  {
    cout << "Essa posição não existe. A lista tem " << size << " elementos" << endl;
    return;
  }
  if (position == 1)
  {
    addFront(data);
    return;
  }
  Node *node = new Node(data), *aux = head;
  for (Data i = 1; i < position - 1; i++)
    aux = aux->next;
  node->next = aux->next;
  node->prev = aux;
  aux->next = node;
  if (aux == tail)
    tail = node;
  size++;
  return;
}

bool LinkedList::checkRemove()
{
  if (empty())
  {
    cout << "A lista está vazia, não há o que remover." << endl;
    return false;
  }
  if (size == 1)
  {
    head = NULL;
    tail = NULL;
    size--;
    return false;
  }
  else
    return true;
}

void LinkedList::removeFront()
{
  if (!checkRemove())
    return;
  Node *aux = head;
  head = head->next;
  delete aux;
  size--;
}

void LinkedList::removeBack()
{
  if (!checkRemove())
    return;
  Node *aux = tail->prev, *aux2 = tail;
  aux->next = NULL;
  tail = aux;
  delete aux2;
  size--;
}

void LinkedList::removeNode(Node *node)
{
  if (head == NULL || node == NULL)
    return;
  if (head == node)
    head = node->next;
  if (node->next != NULL)
  {
    tail = node->prev;
    node->next->prev = node->prev;
  }
  if (node->prev != NULL)
    node->prev->next = node->next;
  delete node;
  size--;
}

void LinkedList::removeInPosition(int position)
{
  if (empty())
  {
    cout << "A lista está vazia, não há o que remover." << endl;
    return;
  }
  if (position < 1)
  {
    cout << "A posição tem de ser maior ou igual a 1." << endl;
    return;
  }
  if (position > size)
  {
    cout << "Essa posição não existe. A lista tem " << size << " elementos" << endl;
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

  Node *aux = head;
  for (Data i = 1; aux != NULL && i < position; i++)
    aux = aux->next;
  removeNode(aux);
  return;
}

void LinkedList::print()
{
  Node *aux = head;
  cout << "[ ";
  while (aux != NULL)
  {
    if (aux->next == NULL)
    {
      cout << aux->data << ' ';
      break;
    }
    cout << aux->data << ", ";
    aux = aux->next;
  }
  cout << "]" << endl;
}

bool LinkedList::checkWord(string word, Node *startingPoint)
{
  if (startingPoint->next == NULL)
    return false;
  int size = word.size(), loop = 0;
  Node *one = startingPoint, *two;
  while (loop < 1)
  {
    two = one;
    for (int i = 0; i < size && two->next != NULL; i++, two = two->next)
    {
      if (two->data != word[i])
        return false;
      if (two->data == word[i])
        continue;
      if (two->next->next == NULL)
        continue;
    }
    // if (two->next != NULL)
    // {
    //   /* code */
    // }

    if (two->data == ' ' || two->data == '.' || two->data == ',' || two->data == word[size - 1])
      loop++;
    one = one->next;
  }
  return true;
}

int LinkedList::countWord(string word)
{
  int size = word.size(), countC, countW = 0;
  Node *one = head;
  while (one != NULL)
  {
    if (one->data == word[0])
      if (checkWord(word, one))
        countW++;
    one = one->next;
  }
  return countW;
}

void LinkedList::changeWord(string oldWord, string newWord)
{
  if (oldWord == newWord)
    return;
  int oldSize = oldWord.size(), newSize = newWord.size();
  string aux;
  Node *one = head, *two;
  if (oldSize == newSize)
  {
    while (one != NULL)
    {
      if (one->data == oldWord[0])
      {
        aux = oldWord;
        if (checkWord(aux, one))
        {
          two = one;
          for (int i = 0; i < oldSize && two != NULL; i++, two = two->next)
          {
            two->data = aux[i] = newWord[i];
            if (two->next == NULL)
              two->data = newWord[oldSize - 1];
          }
        }
      }
      one = one->next;
    }
  }
  else if (oldSize > newSize)
  {
    cout << "a palavra velha é maior" << endl;
  }
  else
  {
    cout << "a palavra nova é maior" << endl;
  }
}