#include <iostream>
#include <stack>
using namespace std;

int valid(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            stack.push(str[i]);
        }
        else
        {
            if (!stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                stack.push(str[i]);
            }
        }
    }
    int a = 0, b = 0;
    while (!stack.empty())
    {
        if (stack.top() == '{')
            a++;
        else if (stack.top() == '}')
            b++;

        stack.pop();
    }
    return (a + 1) / 2 + (b + 1) / 2;
}

int main()
{
    string str = "{{}}}{";
    cout << valid(str) << endl;
}