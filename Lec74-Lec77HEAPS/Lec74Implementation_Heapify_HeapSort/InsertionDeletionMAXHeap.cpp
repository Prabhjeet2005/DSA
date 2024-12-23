#include <iostream>
using namespace std;

class Heap
{
public:
  int arr[100];
  int size;

  Heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int data)
  {
    size += 1;
    int index = size;
    arr[index] = data;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[index] > arr[parent]) //  For Min Heap ==> (arr[index] < arr[parent])
      {
        swap(arr[index], arr[parent]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  }

  void deleteFromHeap()
  {
    if (size == 0)
    {
      cout << "UnderFlow\n";
      return;
    }
    int i = 1;
    arr[1] = arr[size];
    size--;

    while (i < size)
    {
      int leftChild = 2 * i;
      int rightChild = 2 * i + 1;

      if (leftChild <= size && arr[i] <= arr[leftChild] && arr[leftChild] >= arr[rightChild])
      {
        swap(arr[i], arr[leftChild]);
        i = leftChild;
      }
      else if (rightChild <= size && arr[i] <= arr[rightChild] && arr[rightChild] > arr[leftChild])
      {
        swap(arr[i], arr[rightChild]);
        i = rightChild;
      }
      else
      {
        return;
      }
    }
  }

  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};



int main()
{
  Heap h;
  h.insert(50);
  h.insert(51);
  h.insert(55);
  h.insert(10);
  h.insert(20);
  h.insert(54);
  cout << "Heap After Insertion: ";
  h.print();
  cout << "Heap After Deletion: ";
  h.deleteFromHeap();
  h.print();
  // -1 55 50 54 10 20 51
  // Deletion(Last element put First):  -1 54 50 51 10 20
}

//     55
//    /  \
//   53  54
//  / \
// 52  50