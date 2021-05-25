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

  // while (text.get(character))
  // {
  //   list.addBack(character);
  // }

  while (text >> noskipws >> character)
  {
    cout << character;
    list.addBack(character);
  }

  list.print();
  text.close();

  // cout << list.countWord("inteligencia") << endl;

  return 0;
}

// if (text.is_open())
//   cout << "text.txt is available" << endl;
// else
//   cout << "error at file" << endl;