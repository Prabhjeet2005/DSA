#include <iostream>
#include <fstream>
#define size 5
using namespace std;

template <class T>
class Stack
{
private:
  int top;
  T *arr;

public:
  Stack()
  {
    top = -1;
    arr = new T[size];
  }
  void push(T data)
  {
    if (isFull())
    {
      cout << "OverFlow\n";
      return;
    }
    top++;
    arr[top] = data;
  }
  void pop()
  {
    if (isEmpty())
    {
      cout << "Underflow\n";
      return;
    }
    cout << "Popped Element: " << arr[top] << endl;
    arr[top] = -1;
    top--;
  }
  void peek()
  {
    if (isEmpty())
    {
      cout << "Underflow\n";
      return;
    }
    cout << "Top Element: " << arr[top] << endl;
  }
  bool isEmpty()
  {
    if (top == -1)
    {
      return 1;
    }
    return 0;
  }
  bool isFull()
  {
    if (top == size - 1)
    {
      return 1;
    }
    return 0;
  }
};

int main()
{
  Stack<int> s1;
  Stack<string> s2;

  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.peek();
  s1.pop();
  s1.peek();

  s2.push("P");
  s2.push("a");
  s2.push("Prabhjeeet");
  s2.push("Singh");
  s2.peek();
  s2.pop();
  s2.peek();
}