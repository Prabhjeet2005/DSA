#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack.push(s[i]);
        }
        else
        {
            if (!stack.empty())
            {
                if ((stack.top() == '[' && s[i] == ']') ||
                    (stack.top() == '{' && s[i] == '}') ||
                    (stack.top() == '(' && s[i] == ')'))
                {

                    stack.pop();
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    return stack.empty();
}

int main()
{
    string str = "[()]{}{[()()]()]";
    isValidParenthesis(str) == 1 ? cout << "VALID" << endl : cout << "INVALID" << endl;
}
