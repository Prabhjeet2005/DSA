#include <iostream>
using namespace std;
bool found(int *arr, int size, int key)
{
    if (size == 0)
    {
        return 0;
    }
    if (arr[0] == key)
    {
        return 1;
    }else{
    return found(arr + 1, size - 1, key);
    }
}
int main()
{
    int arr[5] = {1, 2, 99, 4, 5};
    cout << "Enter Key: ";
    int key;
    cin >> key;
    if (found(arr, 5, key) == 1)
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not Found\n";
    }
}