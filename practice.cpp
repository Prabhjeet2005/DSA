#include <iostream>
using namespace std;

class base
{
public:
  int a = 10;
};

class derived
{
  int b;

public:
  derived(int b)
  {
    this->b = b;
  }

  void print()
  {
    cout << "Value of b is: " << b << endl;
  }
};

int main()
{
  derived d(10);
  d.print();
}