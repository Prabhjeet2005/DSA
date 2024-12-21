#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream fout;
  fout.open("Example.txt");
  int arr[5] = {5, 4, 3, 2, 1};
  fout << "Original List: ";
  for (int i = 0; i < 5; i++)
  {
    fout << arr[i] << " ";
  }
  for (int i = 0; i < 4; i++)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (arr[i] > arr[j])
      {
        swap(arr[i], arr[j]);
      }
    }
  }
  fout << "\nSorted List: ";
  for (int i = 0; i < 5; i++)
  {
    fout << arr[i] << " ";
  }
  fout << "\n";
  fout.close();

  ifstream fin;
  fin.open("Example.txt");
  string line;
  while(getline(fin,line)){
    cout << line << endl;
  }

  fin.close();
}