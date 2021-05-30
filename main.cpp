#include "LinkedList.h"

#include <fstream>

int main()
{
  LinkedList linkedList;

  string file = "inteligenciaEmocional.txt";

  char character;

  fstream textFileIn(file);

  while (textFileIn >> noskipws >> character)
  {
    linkedList.insertAtTail(character);
  }

  linkedList.printList();

  textFileIn.close();

  fstream textFileOut(file, ios::out | ios::trunc);
  cin >> character;
  textFileOut.put(character);
  textFileOut.close();
  return 0;
}
