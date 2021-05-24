#include <cstdlib>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main()
{
  char character;
  char END_OF_FILE = '#';

  LinkedList list;

  fstream text("text.txt");

  if (text.is_open())
    cout << "text.txt is available" << endl;
  else
    cout << "error at file" << endl;

  while (text.get(character))
  {
    list.addBack(character);
  }

  list.print();

  text.close();
  return 0;
}