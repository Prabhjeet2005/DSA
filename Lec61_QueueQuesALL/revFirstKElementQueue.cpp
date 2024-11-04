// input {1,2,3,4,5}  k=3
// output {3,2,1,4,5}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> &q, int k)
{
    // add code here.
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(s.top());
        s.pop();
    }
    int size = q.size() - k;
    for (int i = 0; i < size; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> ans;
    int k = 3;
    ans = modifyQueue(q, k);
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}