#include <iostream>
using namespace std;
int sum(int arr[], int size)
{

    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    return (sum(arr+2, size-2) + sum(arr + 1, size - 1));
}
int main()
{
    cout << "Enter Size: ";
    int size;
    cin >> size;
    int arr[100] = {0};
    cout << "Enter Array Elements: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << sum(arr, size);
}