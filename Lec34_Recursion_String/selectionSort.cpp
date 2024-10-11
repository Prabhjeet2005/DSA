#include <iostream>
using namespace std;

//Select Smallest Element

void selectionSort(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    selectionSort(arr + 1, size - 1);
}
int main()
{
    int arr[10] = {2, 45, 25, 74, 245, 9};
    int size = 6;
    cout << "Before:-\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "After:-\n";
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}