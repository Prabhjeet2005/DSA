// Merge k  sorted Array
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
  for (int i = 0; i<k; i++){
    if(kArrays[i][0]){
      node *temp = new node(kArrays[i][0], i, 0);
      minHeap.push(temp);
    }
  }
  vector<int> ans;

  while(!minHeap.empty()){
    node *top = minHeap.top();
    minHeap.pop();
    ans.push_back(top->data);
    int row = top->row;
    int col = top->col;
    if(col+1 < kArrays[row].size() ){
      node *temp = new node(kArrays[row][col + 1], row, col + 1);
      minHeap.push(temp);
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