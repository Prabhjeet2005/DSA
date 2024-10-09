#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 21
//Give the Nth Number
int fib(int n)
{
    // BAse Case n==0, n==1
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}
int main()
{
    cout << "Enter N: ";
    int n;
    cin >> n;
    cout << fib(n);
}