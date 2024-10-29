#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int> arr, int n)
{
    stack<int> stack;
    stack.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (stack.top() != -1 && arr[stack.top()] >= arr[i]) //HERE MISTAKE 
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> arr, int n)
{
    stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (stack.top()!=-1 && arr[stack.top()] >= arr[i])
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();

    vector<int> next(n);
    next=nextSmaller(heights, n);

    vector<int> prev(n);
    prev=prevSmaller(heights, n);
    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int length = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        area = max((length * breadth), area);
    }
    cout << area << endl;
}