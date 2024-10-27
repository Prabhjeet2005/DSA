#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(stack<char> &stack, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' ||
            ch == '+' || ch == '-' ||
            ch == '*' || ch == '/')
        {
            stack.push(str[i]);
        }
        else
        {
            // Either ')' or LOWERCASE
            if (ch == ')')
            {
                bool isRedundant = true;

                while (stack.top() != '(')
                {
                    if (stack.top() == '+' || stack.top() == '-' ||
                        stack.top() == '*' || stack.top() == '/')
                    {

                        isRedundant = false;
                    }
                    stack.pop();
                }
                if (isRedundant == true)
                {
                    return true;
                }
                stack.pop();
                        }
        }
    }
    return false;
}

int main()
{
    stack<char> stack;
    string str = "((a+b)";

    cout << findRedundantBrackets(stack, str) << endl;
}