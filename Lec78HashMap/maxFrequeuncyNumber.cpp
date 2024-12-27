#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Ninja is given an array of integers that contain numbers in random order.
He needs to write a program to find and return the number which occurs
the maximum times in the given input. He needs your help to solve this problem.
If two or more elements contend for the maximum frequency,
return the element which occurs in the array first i.e. whose index is lowest.
For example,
For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
*/

int getMaxFreqElement(vector<int> &arr, int n)
{
  unordered_map<int, int> unorderedMap;
  int ans = 0;
  int maxFreq = 0;
  for (int i = 0; i < n; i++)
  {
    unorderedMap[arr[i]]++;
    maxFreq = max(maxFreq, unorderedMap[arr[i]]);
  }

  for (int i = 0; i < n; i++)
  {
    if (maxFreq == unorderedMap[arr[i]])
    {
      ans = arr[i];
      break;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2};
  int size = arr.size();

  cout << "Max Frequency is: " << getMaxFreqElement(arr, size) << endl;
}