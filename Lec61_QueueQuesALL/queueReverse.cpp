#include <iostream>
#include <queue>
#include <stack>
using namespace std;


//STACK

// queue<int> rev(queue<int> q)
// {
//     stack<int> stack;
//     queue<int> ans;
//     int size = q.size();
//     for (int i = 0; i < size; i++)
//     {
//         stack.push(q.front());
//         q.pop();
//     }
//     for (int i = 0; i < size; i++)
//     {
//         ans.push(stack.top());
//         stack.pop();
//     }
//     return ans;
// }


//RECURSION

void rev(queue<int> &q){
    if(q.empty()){
        return;
    }
    int pop = q.front();
    q.pop();
    rev(q);
    q.push(pop);
}

void print(queue<int> q, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        q.push(i);
    }
    queue<int> ans;
    print(q, size);
    // ans = rev(q);
    rev(q);
    print(q, size);
}