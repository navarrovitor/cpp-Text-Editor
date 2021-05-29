#include <cstdlib>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main()
{

  char character;

  LinkedList list;

  fstream text("text.txt");

  while (text >> noskipws >> character)
  {
    list.addBack(character);
  }

  list.print();

  text.close();

  return 0;
}