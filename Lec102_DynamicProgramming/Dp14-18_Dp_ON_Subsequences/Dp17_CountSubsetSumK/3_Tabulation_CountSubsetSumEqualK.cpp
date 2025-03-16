#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {1, 1, 4, 5};
  int n = arr.size();
  int t = 5;

  vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

  for (int i = 0; i < n; i++)
  {
    dp[i][0] = 1;
  }
  if (arr[0] <= t)
  {
    dp[0][arr[0]] = 1;
  }

  for (int index = 1; index < n; index++)
  {
    for (int target = 1; target <= t; target++)
    {
      int notpick = dp[index - 1][target];
      int pick = 0;
      if (arr[index] <= target)
      {
        pick = dp[index - 1][target - arr[index]];
      }
      dp[index][target] = pick + notpick;
    }
  }
  cout << "No. of Subset Sum Equal To K: " << dp[n-1][t] << endl;
}