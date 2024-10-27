#include <iostream>
#include <stack>
using namespace std;

void insertSort(stack<int> &stack, int x)
{
    if (stack.empty() || x > stack.top())
    {
        stack.push(x);
        return;
    }
    else
    {
        int num = stack.top();
        stack.pop();

        insertSort(stack, x);
        stack.push(num);
    }
}

void stackSort(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    stackSort(stack);
    insertSort(stack, num);
}

int main()
{
    stack<int> stack;
    stack.push(4);
    stack.push(-3);
    stack.push(7);
    stack.push(-2);
    stack.push(1);
    stack.push(10);

    stackSort(stack);
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}