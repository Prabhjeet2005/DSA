#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
  int smallest = i;
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;

  if (leftChild < n && arr[leftChild] > arr[smallest])
  {
    smallest = leftChild;
  }
  if (rightChild < n && arr[rightChild] > arr[smallest])
  {
    smallest = rightChild;
  }
  if (smallest != i)
  {
    swap(arr[smallest], arr[i]);
    heapify(arr, n, smallest);
  }
}

void heapSort(vector<int> &arr, int n)
{
  int size = n;
  while (size > 0)
  {
    swap(arr[size], arr[0]);
    size--;

    heapify(arr, size, 0);
  }
}

int main()
{
  vector<int> arr = {2, 3, 1, 20, 15};
  int n = arr.size() - 1;
  int k = 4;
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  heapSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    if(i == k-1){
      cout << arr[i] << endl;
    }
  }
  cout << endl;
}