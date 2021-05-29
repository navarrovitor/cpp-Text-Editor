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

  /* front ... position n ... back */
  void insertHead(char element);
  void insertTail(char element);
  void insertInPosition(int position, char element);

  void removeHead();
  void removeTail();
  void removeInPosition(int position);

  void loadTxt(fstream text);
  void countWord(string word);
  void changeWord(string oldWord, string newWord);
  void printList();
  void saveTxt(fstream text);
};