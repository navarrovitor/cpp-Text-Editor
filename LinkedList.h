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

  void insertAtHead(char element);
  void insertAtTail(char element);
  // void insertInPosition(int position, char element);

  // void removeAtHead();
  // void removeAtTail();
  // void removeInPosition(int position);

  // void loadTxt(fstream text);
  // void countWord(string word);
  // void changeWord(string oldWord, string newWord);
  // void saveTxt(fstream text);
};