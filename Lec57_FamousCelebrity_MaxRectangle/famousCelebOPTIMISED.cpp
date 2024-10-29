#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    stack<int> stack;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        stack.push(i);
    }
    while (stack.size() > 1)
    {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        if (arr[a][b] == 1)
        {
            stack.push(b);
        }
        else
        {
            stack.push(a);
        }
    }
    int candidate = stack.top();
    bool colCheck = true, rowCheck = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[candidate][i] == 1)
        {
            colCheck = false;
            break;
        }
        if (arr[i][candidate] == 0 && i != candidate)
        {
            rowCheck = true;
            break;
        }
    }
    if (rowCheck == false && colCheck == true)
    {
        cout << "CELEBRITY: " << candidate << endl;
    }
    else
    {
        cout << "-1";
    }
}