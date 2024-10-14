#include <iostream>
using namespace std;

// MergeSort Function->Left and Right part Sort
// Merge Function    -> 2 Temporary Arrays Copy Elements into them Then Sort

int merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int inversionCount = 0;
    // Create Empty
    int *first = new int[len1];
    int *second = new int[len2];
    // Copying into Empty
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    int index1 = 0, index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k++] = second[index2++];
            inversionCount = len1 - index1;
        }
    }
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;
    return inversionCount;
}

int mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int inversionCount = 0;
    int mid = s + (e - s) / 2;
    inversionCount += mergeSort(arr, s, mid);
    inversionCount += mergeSort(arr, mid + 1, e);
    inversionCount += merge(arr, s, e);
    return inversionCount;
}

int main()
{
    int arr[6] = {3, 1, 2, 5, 4};
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << mergeSort(arr, 0, size - 1) << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}