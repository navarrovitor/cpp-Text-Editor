#include "Node.h"

class LinkedList
{
private:
  Node *head;
  Node *tail;
  Data size;

public:
  LinkedList();

  void addFront(Data data);
  void addBack(Data data);
  void addInPosition(Data data, int position);
  void removeFront();
  void removeBack();
  void removeInPosition(int position);

  void print();

  int countWord(string word);
  void changeWord(string oldWord, string newWord);

  int troca(Node *c, int pos, int i, string s);
  int trocaPalavra(string s, string stroca);
};