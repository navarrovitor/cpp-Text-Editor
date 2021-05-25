#include "Node.h"

class LinkedList
{
private:
  Node *head;
  Node *tail;
  Data size;

public:
  LinkedList();

  bool empty();
  int qty();
  Data frontValue();
  Data backValue();

  void addInEmpty(Data data);
  void addFront(Data data);
  void addBack(Data data);
  void addInPosition(Data data, int position);
  bool checkRemove();
  void removeFront();
  void removeBack();
  void removeNode(Node *node);
  void removeInPosition(int position);

  void print();

  int countWord(string word);

  // void removeDuplicates();
};