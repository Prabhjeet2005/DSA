#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
  int pivotElement = arr[s];
  int cnt = 0;
  for (int i = s + 1; i <= e; i++)
  {
    if (arr[i] <= pivotElement)
    {
      cnt++;
    }
  }
  int pivotIndex = s + cnt;
  swap(arr[s], arr[pivotIndex]);

  int i = s, j = e;
  int k = 0;
  while (i < pivotIndex && j > pivotIndex)
  {
    while (arr[i] < pivotElement)
    {
      i++;
    }
    while (arr[j] > pivotElement)
    {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
  if (s >= e)
  {
    return;
  }
  int p = partition(arr, s, e);
  quickSort(arr, s, p - 1);
  quickSort(arr, p + 1, e);
}

int main()
{
  int arr[6] = {3, 2, 54, 6, 2, 5};
  int size = 6;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  quickSort(arr, 0, size - 1);
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}