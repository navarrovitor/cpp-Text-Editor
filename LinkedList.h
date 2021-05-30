#include <fstream>

#include "Node.h"

class LinkedList
{
private:
  Node *head;
  Node *tail;
  int quantityOfNodes;

public:
  LinkedList();

  bool empty();
  int header();
  int trailer();
  int nOfNodes();

  void printList();

  void insertAtHead(char);
  int insertAtPosition(int, char);
  void insertAtTail(char);

  char removeHead();
  char removePosition(int);
  char removeTail();

  // void loadTxt(fstream text);
  int countWord(string word);
  // void changeWord(string oldWord, string newWord);
  // void saveTxt(fstream text);
};