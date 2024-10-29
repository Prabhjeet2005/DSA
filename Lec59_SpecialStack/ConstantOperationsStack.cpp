#include <iostream>
#include <stack>
using namespace std;
void minimum(stack<int> qstack, int mini, stack<int> &stack)
{
    if (qstack.empty())
    {
        return;
    }
    int num = qstack.top();
    mini = min(mini, qstack.top());
    qstack.pop();
    stack.push(mini);
    minimum(qstack, mini, stack);

}

int main()
{
    stack<int> qstack;
    qstack.push(5);
    qstack.push(3);
    qstack.push(8);
    qstack.push(2);
    qstack.push(4);
    int mini = INT_MAX;
    stack<int> stack;
    minimum(qstack, mini, stack);
    int n;
    cin >> n;
    while (qstack.top() != n)
    {
        qstack.pop();
        stack.pop();
    }
    cout << "For " << n << " minimum is : " << stack.top() << endl;
}