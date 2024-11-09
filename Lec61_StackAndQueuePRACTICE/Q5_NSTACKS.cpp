#include <iostream>
using namespace std;

class NStacks
{
    int *arr;
    int *next;
    int *top;
    int size;
    int freespot = 0, n;

public:
    NStacks(int size, int n)
    {
        this->size = size;
        this->n = n;
        arr = new int[size];

        next = new int[size];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;

        top = new int[n];
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
    }
    void push(int n, int x)
    {
        if (freespot == -1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[n - 1];
        top[n - 1] = index;
    }
    int pop(int n)
    {
        if (top[n - 1] == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        int index = top[n - 1];
        top[n - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    NStacks s(6, 3);
    s.push(1, 10);
    s.push(1, 20);
    s.push(1, 30);
    s.push(1, 40);
    s.push(1, 50);
    s.push(1, 10);
    s.push(1, 60);
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
}