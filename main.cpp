#include "LinkedList.h"

#include <fstream>

int main()
{
  LinkedList linkedList;
  int option;
  string file = "inteligenciaEmocional.txt";

  char character;
  fstream textFileIn(file);
  while (textFileIn >> noskipws >> character)
    linkedList.insertAtTail(character);
  textFileIn.close();

  linkedList.changeWord("percepsao", "percepcao");
  cout << linkedList.countWord("percepcao") << endl;
  // fstream textFileOut(file, ios::out | ios::trunc);
  // while (!linkedList.empty())
  //   textFileOut.put(linkedList.removeHead());

  // textFileOut.close();
  return 0;
}
