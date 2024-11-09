#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        top++;
        if (top >= size)
        {
            top--;
            cout << "Overflow" << endl;
            return;
        }
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        return val;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
}