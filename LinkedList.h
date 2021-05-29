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
  void insertFront(char element);
  void insertBack(char element);
  void insertInPosition(int position, char element);

  void removeFront();
  void removeBack();
  void removeInPosition(int position);

  void loadTxt(fstream text);
  void saveTxt(fstream text);
  void countWord(string word);
  void changeWord(string oldWord, string newWord);
};