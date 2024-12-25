#include <iostream>
#include <vector>
#include <queue>
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
    this->col = col;
    this->row = row;
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

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
  priority_queue<node *, vector<node *>, compare> minHeap;

  for (int i = 0; i < k; i++)
  {
    node *temp = new node(kArrays[i][0], i, 0);
    minHeap.push(temp);
  }

  vector<int> ans;
  while (!minHeap.empty())
  {
    node *topHeap = minHeap.top();
    minHeap.pop();
    ans.push_back(topHeap->data);

    int row = topHeap->row;
    int col = topHeap->col;

    if (col + 1 < kArrays[row].size()) // If next element of inputted element in Heap Exists
    {
      node *next = new node(kArrays[row][col + 1], row, col + 1);
      minHeap.push(next);
    }
  }
  return ans;
}
int main()
{
  vector<vector<int>> kArrays = {{1, 5, 9}, {45, 90}, {2, 6, 78, 100, 234}, {0}};
  int k = 4;

  vector<int> ans = mergeKSortedArrays(kArrays, k);

  cout << "Final Vector: ";
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}