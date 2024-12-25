#include <iostream>
using namespace std;
// TC=> 2^n
int climb(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    return climb(n - 1) + climb(n - 2);
}
int main()
{
    cout << "Enter N: ";
    int n;
    cin >> n;
    cout << climb(n);
    return 0;
}
