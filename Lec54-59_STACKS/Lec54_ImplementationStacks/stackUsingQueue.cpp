#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class SQueue
{
    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        while (size != 0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    int pop()
    {
        if (q.empty())
        {
            cout << "Queue Empty & returned ";
            return -1;
        }
        int front = q.front();
        q.pop();
        return front;
    }
    int top()
    {
        if (q.empty())
        {
            cout << "Queue Empty & returned ";
            return -1;
        }
        return q.front();
    }
};

int main()
{
    SQueue s;
    s.push(10);
    cout << s.top() << endl;
    s.push(20);
    cout << s.top() << endl;
    s.push(30);
    cout << s.top() << endl;
    s.push(40);
    cout << s.top() << endl;
    cout << s.pop() << endl;
}