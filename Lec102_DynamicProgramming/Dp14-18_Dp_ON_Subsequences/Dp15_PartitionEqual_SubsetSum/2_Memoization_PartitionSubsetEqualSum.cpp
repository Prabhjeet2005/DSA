#include <iostream>
#include <vector>
using namespace std;

bool subsetSumEqual(int index, int target, vector<vector<int>> &dp, vector<int> &arr)
{
  if (target == 0)
  {
    return true;
  }
  if (index == 0)
  {
    return arr[0] == target;
  }

  if (dp[index][target] != -1)
  {
    return dp[index][target];
  }

  bool notPick = subsetSumEqual(index - 1, target, dp, arr);
  bool pick = false;
  if (arr[index] <= target)
  {
    pick = subsetSumEqual(index - 1, target - arr[index], dp, arr);
  }

  return dp[index][target] = pick || notPick;
}

int main()
{
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  int n = arr.size();

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  if (sum % 2 == 0)
  {
    if (subsetSumEqual(n - 1, sum / 2, dp, arr)) // target = sum/2
    {
      cout << "Subset Exists" << endl;
    }
    else
    {
      cout << "Subset Doesn't Exists" << endl;
    }
  }
  else
  {
    cout << "Subset Doesn't Exists" << endl;
  }
}