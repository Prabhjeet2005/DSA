#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream fin;
  fin.open("Example.txt");
  char c;
  c = fin.get();

  while (!fin.eof())
  {
    cout << c;
    c = fin.get();
  }

  fin.close();
}