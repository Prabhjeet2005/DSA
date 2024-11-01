#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2,1,4,3};
    // OUTPUT :   {1,-1,3,-1}
    int n = 4;
    stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);
    // cout << stack.top();
    for (int i = n - 1; i >= 0; i--)
    {
        while (stack.top() >= arr[i])
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}