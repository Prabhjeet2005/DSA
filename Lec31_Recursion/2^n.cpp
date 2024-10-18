#include <iostream>
using namespace std;

//TC-> O(n)

int twon(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }
    // recursive Relation
    return 2 * twon(n - 1);
}
int main()
{
    cout << "Enter N: ";
    int n;
    cin >> n;
    cout << twon(n) << endl;
    return 0;
}