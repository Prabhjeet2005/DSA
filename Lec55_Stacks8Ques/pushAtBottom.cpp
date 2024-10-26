#include <iostream>
#include <stack>
using namespace std;
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    if (myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }
    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack, x);

    myStack.push(num);
    return myStack;
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
   
   ans = pushAtBottom(myStack, 10);
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}