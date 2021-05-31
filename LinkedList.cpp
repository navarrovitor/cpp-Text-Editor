#include "LinkedList.h"

#include <cstring>
#include <typeinfo>

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

char LinkedList::removeHead()
{
  int character = head->getElement();
  if (empty())
    return -1;
  if (head->getNext() == NULL)
  {
    head = NULL;
    tail = NULL;
  }
  else
  {
    head = head->getNext();
    head->setPrev(NULL);
  }
  quantityOfNodes--;
  return character;
}

char LinkedList::removePosition(int position)
{
  int limit = nOfNodes() + 1, half = nOfNodes() / 2, size = nOfNodes();
  if (empty() || position < 1 || position > limit)
    return -1;
  if (position == 1)
    return this->removeHead();
  if (position == size)
    return this->removeTail();
  Node *indicator, *helper;
  int character;
  if (position <= half)
  {
    indicator = head;
    for (int j = 0; j < position - 2; j++)
      indicator = indicator->getNext();
    character = indicator->getNext()->getElement();
    helper = indicator->getNext()->getNext();
    helper->setPrev(indicator);
    indicator->setNext(helper);
  }
  else
  {
    indicator = tail;
    for (int j = size; j > position + 1; j--)
      indicator = indicator->getPrev();
    character = indicator->getPrev()->getElement();
    helper = indicator->getPrev()->getPrev();
    helper->setNext(indicator);
    indicator->setPrev(helper);
  }
  quantityOfNodes--;
  return character;
}

char LinkedList::removeTail()
{
  int character = tail->getElement();
  if (empty())
    return -1;
  if (head->getNext() == NULL)
  {
    character = head->getElement();
    head = NULL;
    tail = NULL;
  }
  else
  {
    tail = tail->getPrev();
    tail->setNext(NULL);
  }
  quantityOfNodes--;
  return character;
}

int LinkedList::countWord(string word)
{
  int countCharacter = 0, countWord = 0;
  char character;
  for (Node *indicator = head; indicator != NULL; indicator = indicator->getNext())
  {
    character = indicator->getElement();
    if (stopCharacter(character))
    {
      if (countCharacter == word.size())
        countWord++;
      countCharacter = 0;
    }
    else
    {
      if (character == word[countCharacter])
        countCharacter++;
    }
  }
  return countWord;
}

int LinkedList::swap(char oldWord[], char newWord[], int wordSize)
{
  Node *helper = head;
  int beggining = 0, counter = 0;
  for (int i = 0; i < nOfNodes(); i++, helper = helper->getNext())
  {
    bool checker = tolower(helper->getElement()) == tolower(oldWord[0]);
    if (checker)
    {
      for (int j = 0; j < wordSize; j++)
      {
        if (tolower((helper->getElement())) == tolower(oldWord[j]))
        {
          counter++;
          i++;
          helper = helper->getNext();
        }
        else
        {
          counter = 0;
          break;
        }
      }
      if (((helper->getElement() == trailer()) || stopCharacter(helper->getElement())) && (counter == wordSize))
      {
        beggining = (i - counter) + 1;
        return beggining;
      }
      else
        counter = 0;
      if (checker)
      {
        i--;
        continue;
      }
    }
  }
  return beggining;
}

void LinkedList::changeWord(string oldWord, string newWord)
{
  int i, oldSize = oldWord.length(), newSize = newWord.length(), wordOcurrences = countWord(oldWord);
  char oldWordInChar[oldSize], newWordInChar[newSize];

  for (i = 0; i < oldSize; i++)
    oldWordInChar[i] = oldWord[i];
  for (i = 0; i < newSize; i++)
    newWordInChar[i] = newWord[i];

  for (int j = 0; j < wordOcurrences; j++)
  {
    int beggining = swap(oldWordInChar, newWordInChar, oldSize);

    for (i = 0; i < oldSize; i++)
      removePosition(beggining);
    for (i = newSize - 1; i >= 0; i--)
      insertAtPosition(beggining, newWordInChar[i]);
  }
}
