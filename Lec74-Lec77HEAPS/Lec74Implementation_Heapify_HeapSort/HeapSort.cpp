#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
  int largest = i;
  int leftChild = 2 * i;
  int rightChild = 2 * i + 1;

  if (leftChild <= n && arr[leftChild] > arr[largest])
  {
    largest = leftChild;
  }
  if (rightChild <= n && arr[rightChild] > arr[largest])
  {
    largest = rightChild;
  }
  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(vector<int> &arr, int n)
{
  int size = n;
  while (size > 1)
  {
    swap(arr[1], arr[size]);
    size--;
    heapify(arr, size, 1);
  }
}

int main()
{
  vector<int> arr = {-1, 45, 55, 60, 50, 70};
  int n = arr.size() - 1;

  for (int i = n / 2; i >= 1; i--)
  {
    // Max Heap
    heapify(arr, n, i);
  }
  cout << "After Heapify: ";
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "After Heap Sort: ";
  heapSort(arr, n);
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
}