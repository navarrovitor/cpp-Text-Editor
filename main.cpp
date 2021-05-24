#include <cstdlib>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main()
{
  fstream text("text.txt", ios::in | ios::out | ios::trunc);
  if (text.is_open())
    cout << "text.txt is available" << endl;
  else
    cout << "error at file" << endl;
  text.close();
  return 0;
}