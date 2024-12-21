#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream orig;
  orig.open("Example.txt");
  ofstream copy;
  copy.open("Copy.txt");

  string line;
  while(getline(orig,line)){
    copy << line << endl;
  }
  orig.close();
  copy.close();
}