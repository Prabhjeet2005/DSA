#include <iostream>
#include<fstream>
using namespace std;

int main()
{
  ofstream fout;
  fout.open("Example.txt");
  fout << "This is Written from fileHandling cpp";
  fout.close();
}