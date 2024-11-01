#include <iostream>
#include <stack>
using namespace std;
class NStacks
{
    int *arr;
    int *next;
    int *top;
    int n, s, freespace = 0;

public:
    NStacks(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
    }
    void push(int x, int m)
    { // m ==> no. of STACK
        if (freespace == -1)
        {
            cout << "false" << endl;
        }
        // FIND INDEX
        int index = freespace;
        // UPDate FREESPACE
        freespace = next[index];
        // INSERT IN Array
        arr[index] = x;
        // Next UPDATE
        next[index] = top[m - 1];
        // top UPDATE
        top[m - 1] = index;
        cout << "true" << endl;
    }

    void pop(int m)
    {
        if (top[m - 1] == -1)
        {
            cout << -1 << endl;
            return;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespace;
        freespace = index;
        cout << arr[index] << endl;
    }
};

int main()
{
    NStacks n1(3, 6);
    n1.push(10, 1);
    n1.push(20, 1);
    n1.push(30, 2);
    n1.pop(1);
    n1.pop(2);
    n1.pop(2);
    n1.pop(2);
}

/*Problem statement
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :

Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= S <= 1000
1 <= Q <= 10^5
1 <= P <= 2
1 <= X <= 10^5

Time Limit: 1 sec

Where ‘S’ represents the size of the array, ‘N’ represents the number of stacks, ‘Q’ represents the number of queries, ‘P’ represents the type of operation and ‘X’ represents the element.
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True
True
True
20
30
Explanation 1 :
For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
Operations performed on the stack are as follows:
push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
pop(1): Pop the top element from the 1st stack. This returns 20.
pop(2): Pop the top element from the 2nd stack. This returns 30.*/