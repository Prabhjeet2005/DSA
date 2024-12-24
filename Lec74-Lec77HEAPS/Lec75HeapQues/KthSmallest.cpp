#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
  int largest = i;
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;

  if (leftChild < n && arr[leftChild] > arr[largest])
  {
    largest = leftChild;
  }
  if (rightChild < n && arr[rightChild] > arr[largest])
  {
    largest = rightChild;
  }
  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

int main()
{

  vector<int> arr = {2, 3, 1, 20, 15};
  int k = 4;

  for (int i = k / 2 - 1; i >= 0; i--)
  {
    heapify(arr, k, i);
  }

  for (int i = k; i < arr.size(); i++)
  {
    if (arr[0] > arr[i])
    {
      arr[0] = arr[i];
      heapify(arr, k, 0);
    }
  }
  cout << "Kth Smallest: " << arr[0]<<endl;
}