#include "LinkedList.h"

#include <fstream>

int main()
{
  LinkedList linkedList;

  char character;

  fstream textFile("inteligenciaEmocional.txt");

  while (textFile >> noskipws >> character)
  {
    linkedList.insertAtTail(character);
  }

  linkedList.printList();

  textFile.close();
  return 0;
}
