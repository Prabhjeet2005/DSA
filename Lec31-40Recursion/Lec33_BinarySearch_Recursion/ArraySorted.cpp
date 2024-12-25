#include <iostream>
using namespace std;

// TC=>O(n)
bool isSorted(int arr[], int size)
{
    if (size <= 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return isSorted((arr + 1), size - 1);
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    bool ans = isSorted(arr, 6);
    if (ans == 0)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
    cout << endl;
    return 0;
}