#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int countSubsets(int index, int target, vector<int> arr)
{
  if (target == 0)
  {
    return 1;
  }
  if (index == 0)
  {
    return arr[index] == target;
  }
  int notPick = countSubsets(index - 1, target, arr);
  int pick = 0;
  if (arr[index] <= target)
  {
    pick = countSubsets(index - 1, target - arr[index], arr);
  }
  return pick + notPick;
}

int main()
{
  vector<int> arr = {1, 1, 4, 5}; // 3
  int target = 5;
  int n = arr.size();
  cout << "No. of Subset With Sum Equal To K: " << countSubsets(n - 1, target, arr) << endl;
}