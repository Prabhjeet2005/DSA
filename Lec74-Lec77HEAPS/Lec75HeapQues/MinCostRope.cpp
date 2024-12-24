#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {4, 3, 2, 6};
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (auto i : arr)
  {
    minHeap.push(i);
  }

  int cost = 0;
  int size = minHeap.size();
  while (size > 1)
  {
    int a = minHeap.top();
    minHeap.pop();
    int b = minHeap.top();
    minHeap.pop();

    int sum = a + b;
    cost += sum;

    minHeap.push(sum);
    size--;
  }

  cout << "Total Minimum Cost: " << cost << endl;
}