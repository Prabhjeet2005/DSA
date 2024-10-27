#include <iostream>
#include <stack>
using namespace std;
void pushAtBottom(stack<int> &s, int x)
{
    // Write your code here.
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    pushAtBottom(s, x);

    s.push(num);
    return;
}
int main()
{
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    stack<int> ans;

    pushAtBottom(myStack, 10);
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
}