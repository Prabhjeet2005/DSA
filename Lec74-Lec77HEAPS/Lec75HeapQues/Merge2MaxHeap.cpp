//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <iostream>
#include <queue>
#include<vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
  void heapify(vector<int> &ans, int index, int n)
  {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && ans[leftChild] > ans[largest])
    {
      largest = leftChild;
    }
    if (rightChild < n && ans[rightChild] > ans[largest])
    {
      largest = rightChild;
    }

    if (largest != index)
    {
      swap(ans[largest], ans[index]);
      heapify(ans, largest, n);
    }
  }

public:
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
  {
    // your code here
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
      ans.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
      ans.push_back(b[i]);
    }
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(ans, i, size);
    }
    return ans;
  }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
  if (arr1.size() + arr2.size() != merged.size())
  {
    return false;
  }
  arr1.insert(arr1.end(), arr2.begin(), arr2.end());
  sort(arr1.begin(), arr1.end());
  vector<int> mergedCopy = merged;
  sort(mergedCopy.begin(), mergedCopy.end());
  if (arr1 != mergedCopy)
  {
    return false;
  }
  for (int i = 1; i < merged.size(); i++)
  {
    if (merged[i] > merged[(i - 1) / 2])
      return false;
  }
  return true;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    vector<int> merged, copyA = a, copyB = b;
    Solution obj;
    merged = obj.mergeHeaps(a, b, n, m);
    bool flag = isMerged(copyA, copyB, merged);
    if (flag == false)
      cout << 0 << endl;
    else
      cout << 1 << endl;

    cout << "~" << "\n";
  }
  return 0;
}

// } Driver Code Ends