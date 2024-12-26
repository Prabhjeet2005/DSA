
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int findKthLargestSubarraySum(vector<int> &arr, int k)
{
  priority_queue<int, vector<int>, greater<int>> minHeap;
  for (int i = 0; i < arr.size(); i++)
  {
    int sum = 0;
    for (int j = i; j < arr.size(); j++)
    {
      sum += arr[j];
      if (minHeap.size() < k)
      {
        minHeap.push(sum);
      }
      else
      {
        if (sum > minHeap.top())
        {
          minHeap.pop();
          minHeap.push(sum);
        }
      }
    }
  }
  return minHeap.top();
}

int main()
{
  vector<int> arr = {1, -2, 3, -4, 5};
  int k = 2;
  int size = arr.size();

  cout << "ANS: " << findKthLargestSubarraySum(arr, k) << endl;
}

/*
***************** BRUTE FORCE ***********************
vector<int> findLargestSumSubarrayBruteForce(vector<int> arr, int k)
{
  int size = arr.size();
  vector<int> ans;
  cout << "Correct Till Now\n";
  for (int i = 0; i < size; i++)
  {
    int sum = 0;

    for (int j = i; j < size; j++)
    {
      sum += arr[j];
      ans.push_back(sum);
    }
  }
  sort(ans.begin(), ans.end());

  int index = ans.size() - k;
  cout << "Ans: " << ans[index] << endl;
  return ans;
}

int main()
{
  vector<int> arr = {1, -2, 3, -4, 5};
  int k = 2;

  int size = arr.size();
  vector<int> ans = findLargestSumSubarrayBruteForce(arr, k);
}
*/