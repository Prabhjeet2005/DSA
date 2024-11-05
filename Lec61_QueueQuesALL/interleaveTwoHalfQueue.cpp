#include <iostream>
#include <queue>
using namespace std;

// void interleave(queue<int> &q)
// {
//     int size = q.size();
//     int i = 0, j = q.size() / 2;
//     int a1[100] = {0};
//     int a2[100] = {0};
//     for (int i = 0; i < size / 2; i++)
//     {
//         a1[i] = q.front();
//         q.pop();
//     }
//     for (int i = 0; i < size / 2; i++)
//     {
//         a2[i] = q.front();
//         q.pop();
//     }
//     for (int i = 0; i < size / 2; i++)
//     {
//         q.push(a1[i]);
//         q.push(a2[i]);
//     }
// }

void interleave(queue<int>&q){
    queue<int> newq;
    int size = q.size() / 2;
    for (int i = 0; i < size; i++){
        newq.push(q.front());
        q.pop();
    }

    while(newq.size()>0){
        q.push(newq.front());
        newq.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interleave(q);
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}