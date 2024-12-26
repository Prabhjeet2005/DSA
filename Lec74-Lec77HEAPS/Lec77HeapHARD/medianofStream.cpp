#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int signum(int maxHeapSize, int minHeapSize)
{
  if (maxHeapSize == minHeapSize)
  {
    return 0;
  }
  else if (maxHeapSize < minHeapSize)
  {
    return -1;
  }
  else if (maxHeapSize > minHeapSize)
  {
    return 1;
  }
  cout<<"Invalid Encountered: "<<endl;
  return 100;
}

void callMedian(int element, priority_queue<int, vector<int>, greater<int>> &minHeap,
                priority_queue<int> &maxHeap, int &median)
{
  switch (signum(maxHeap.size(), minHeap.size()))
  {
  case 0: // n n
    if (element > median)
    {
      minHeap.push(element);
      median = minHeap.top();
    }
    else
    {
      maxHeap.push(element);
      median = maxHeap.top();
    }
    break;

  case 1: //  n n-1
    if (element > median)
    {
      minHeap.push(element);
      median = (maxHeap.top() + minHeap.top())/2;
    }
    else
    {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
      maxHeap.push(element);
      median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;

  case -1:  //  n-1 n
    if (element > median)
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
      minHeap.push(element);
      median = (maxHeap.top() + minHeap.top()) / 2;
    }
    else
    {
      maxHeap.push(element);
      median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;
  }
}

vector<int> calculateMedianOfStream(vector<int> &arr, int n)
{
  vector<int> ans;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int median = -1;
  for (int i = 0; i < n; i++)
  {

    callMedian(arr[i], minHeap, maxHeap, median);
    ans.push_back(median);
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 3};
  int n = 3;
  vector<int> ans = calculateMedianOfStream(arr, n);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}