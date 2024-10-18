#include <iostream>
using namespace std;

// TC=> O(n)

void counting(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }
    // recursive Relation
    counting(n - 1); // HEAD RECURSION  OUTPUT:- 1 2 3 4 5 
    cout << n << " ";
}
int main()
{
    cout << "Enter N: ";
    int n;
    cin >> n;
    counting(n);
    cout << endl;
    return 0;
}