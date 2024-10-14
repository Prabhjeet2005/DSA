#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int cnt = 0;
    int piviotElement = arr[s];
    
    // s+1
    for (int i = s + 1; i <= e; i++) 
    {
        if (arr[i] <= piviotElement)
        {
            cnt++;
        }
    }
    int piviotIndex = s + cnt;
    swap(arr[s], arr[piviotIndex]);
    // checking for less than a | a |  greater than a condition
    int i = s, j = e;
    while (i < piviotIndex && j > piviotIndex)
    {
        while (arr[i] <= piviotElement) //  <=
        {
            i++;
        }
        while (arr[j] > piviotElement)
        {
            j--;
        }
        if (i < piviotIndex && j > piviotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return piviotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    //Partition
    int p = partition(arr, s, e);
    //Left Part SOrt
    quickSort(arr, s, p - 1);
    //Right Part Sort
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[6] = {9, 6, 6, 7, 4, 2};
    int size = 6;
    cout << "Before\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, size - 1);
    cout << "After\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}