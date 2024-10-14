#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, size - 1);
}

int main()
{
    int arr[10] = {2, 1, 4, 2, 1, 5};
    int size = 6;
    cout << "Before:- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    bubbleSort(arr, size);
    cout << "\nAfter:- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}