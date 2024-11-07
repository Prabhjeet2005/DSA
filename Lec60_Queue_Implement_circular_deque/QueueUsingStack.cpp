#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class QStack
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }

            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }

            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main()
{
    QStack q;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.peek() << endl;
    q.enqueue(30);
    q.enqueue(40);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
}