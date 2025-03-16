#include <iostream>
#include <vector>
using namespace std;

int countSubset(int index, int target, vector<vector<int>> &dp, vector<int> &arr)
{
  if (target == 0)
  {
    return 1;
  }
  if (index == 0)
  {
    return arr[index] == target;
  }

  if (dp[index][target] != -1)
  {
    return dp[index][target];
  }
  int notpick = countSubset(index - 1, target, dp, arr);
  int pick = 0;
  if (arr[index] <= target)
  {
    pick = countSubset(index - 1, target - arr[index], dp, arr);
  }

  return dp[index][target] = pick + notpick;
}

int main()
{
  vector<int> arr = {1, 1, 4, 5}; // OUTPUT: 3
  int n = arr.size();
  int target = 5;
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
  cout << "No. of Subset With Sum Equal k: " << countSubset(n - 1, target, dp, arr) << endl;
}