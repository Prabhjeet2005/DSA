#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
class node
{
public:
  int data;
  int row;
  int col;
  node(int data, int row, int col)
  {
    this->data = data;
    this->row = row;
    this->col = col;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->data > b->data;
  }
};

int smallestRangeKSortedArrays(vector<vector<int>> &arr, int k)
{
  priority_queue<node *, vector<node *>, compare> minHeap;
  int mini = INT_MAX;
  int maxi = INT_MIN;

  for (int i = 0; i < k; i++)
  {
    int element = arr[i][0];
    maxi = max(maxi, element);
    mini = min(mini, element);
    node *temp = new node(element, i, 0);
    minHeap.push(temp);
  }
  int start = mini, end = maxi;

  while (!minHeap.empty())
  {
    node *top = minHeap.top();
    minHeap.pop();
    mini = top->data;

    if (maxi - mini < end - start)
    {
      start = mini;
      end = maxi;
    }
    if (top->col + 1 < arr[top->row].size())
    {
      maxi = max(maxi, arr[top->row][top->col + 1]);
      node *temp = new node(arr[top->row][top->col + 1], top->row, top->col + 1);
      minHeap.push(temp);
    }
    else
    {
      break;
    }
  }
  return (end - start + 1); // Expected output is +1 of range difference
};

int main()
{
  vector<vector<int>> arr = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
  int k = 3;
  cout << "Range is: " << smallestRangeKSortedArrays(arr, k) << endl;
}