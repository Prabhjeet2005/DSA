#include <iostream>
#include <fstream>
using namespace std;
class Student
{
private:
  string name;
  string gender;
  int age;
  int height;
  double weight;

public:
  void setData()
  {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Age(int): ";
    cin >> age;
    cout << "Enter height(cm): ";
    cin >> height;
    cout << "Enter weight(double): ";
    cin >> weight;
  }
  void getData()
  {
    cout << "Name: " << name << " Gender: " << gender << ", Age: " << age << " Height: " << height << " Weight: " << weight << endl;
  }
};

int main()
{
  Student s[3];
  s.setData();
  ofstream fout;
  fout.open("StudentRecords.txt");
  fout << s << endl;
  fout.close();
  ifstream fin;
  fin.open("StudentRecords.txt");
  string str;
  while (getline(fin, str))
  {
    cout << str << endl;
  }
  fin.close();
}