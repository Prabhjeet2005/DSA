#include <iostream>
#include <vector>
using namespace std;

bool sumSubsetK(int index, int target, vector<vector<int>> &dp, vector<int> &arr)
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

  bool notPick = sumSubsetK(index - 1, target, dp, arr);

  bool pick = false;
  if (arr[index] <= target)
  {
    pick = sumSubsetK(index - 1, target - arr[index], dp, arr);
  }

  return dp[index][target] = pick || notPick;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  int k = 4;
  int n = arr.size();

  vector<vector<int>> dp(n, vector<int>(k+1, -1));

  if (sumSubsetK(n - 1, k, dp, arr))
  {
    cout << "Subset With sum " << k << " Exists" << endl;
  }
  else
  {
    cout << "Subset Doesn't Exist" << endl;
  }
}