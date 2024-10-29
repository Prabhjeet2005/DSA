#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmaller(int *arr, int n)
{
    stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (stack.top() != -1 && arr[stack.top()] >= arr[i])
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

vector<int> prevSmaller(int *arr, int n)
{
    stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (stack.top() != -1 && arr[stack.top()] >= arr[i])
        {
            stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

int rectangleArea(int *arr, int n)
{
    vector<int> next(n);
    next = nextSmaller(arr, n);

    vector<int> prev(n);
    prev = prevSmaller(arr, n);
    int area = -1;

    for (int i = 0; i < n; i++)
    {
        int length = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        area = max(area, (length * breadth));
    }
    return area;
}

int maxArea(int M[4][4], int n, int m)
{
    int area = rectangleArea(M[0], m);

    area = max(rectangleArea(M[0], m), area);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        area = max(rectangleArea(M[i], m), area);
    }
    return area;
}

int main()
{

    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};

    cout << maxArea(M, 4, 4) << endl;
}