#include <iostream>
#include <queue>
using namespace std;

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

// //{ Driver Code Starts
// // Initial Template for C++

// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// // User function Template for C++

// class Solution
// {
// public:
//     vector<int> rearrangeQueue(queue<int> &q)
//     {
//         stack<int> stack;
//         int size = q.size();

//         for (int i = 0; i < size / 2; i++)
//         {
//             stack.push(q.front());
//             q.pop();
//         }

//         while (!stack.empty())
//         {
//             q.push(stack.top());
//             stack.pop();
//         }

//         for (int i = 0; i < size / 2; i++)
//         {
//             q.push(q.front());
//             q.pop();
//         }

//         for (int i = 0; i < size / 2; i++)
//         {
//             stack.push(q.front());
//             q.pop();
//         }

//         while (!stack.empty())
//         {
//             q.push(stack.top());
//             q.push(q.front());
//             q.pop();
//             stack.pop();
//         }

//         vector<int> ans;
//         for (int i = 0; i < size; i++)
//         {
//             ans.push_back(q.front());
//             q.pop();
//         }

//         return ans;
//     }
// };

// //{ Driver Code Starts.

// int main()
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

//         queue<int> q;
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             q.push(a);
//         }
//         Solution ob;
//         vector<int> ans = ob.rearrangeQueue(q);
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i] << " ";
//         }
//         cout << endl;

//         cout << "~" << "\n";
//     }

//     return 0;
// }
// // } Driver Code Ends

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