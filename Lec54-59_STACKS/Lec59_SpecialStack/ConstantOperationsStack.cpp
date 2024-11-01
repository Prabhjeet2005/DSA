#include<iostream>
#include <limits.h>
#include <stack>
using namespace std;
class SpecialStack
{
    stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }
        int curr = s.top();
        s.pop();
        if (curr < mini)
        {
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        else
        {
            int curr = s.top();
            if (curr > mini)
            {
                return curr;
            }
            else
            {
                return mini;
            }
        }
    }

    int getMin()
    {
        // Implement the getMin() function.
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};

int main()
{
    stack<int> qstack;
    qstack.push(5);
    qstack.push(3);
    qstack.push(8);
    qstack.push(2);
    qstack.push(4);

}