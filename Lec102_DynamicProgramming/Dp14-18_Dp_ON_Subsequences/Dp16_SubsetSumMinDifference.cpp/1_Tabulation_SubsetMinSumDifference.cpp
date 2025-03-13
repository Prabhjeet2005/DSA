#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
  vector<int> arr = {3, 1, 5, 2, 8};
  int n = arr.size();
  int totsum = 0;
  for (int i = 0; i < n; i++)
  {
    totsum += arr[i];
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(totsum + 1, false));

  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }

  if (arr[0] <= totsum)
  {
    dp[0][arr[0]] = true;
  }

  for (int index = 1; index < n; index++)
  {
    for (int target = 1; target <= totsum; target++)
    {
      bool notpick = dp[index - 1][target];
      bool pick = false;
      if (arr[index] <= target)
      {
        pick = dp[index - 1][target - arr[index]];
      }
      dp[index][target] = pick || notpick;
    }
  }
  int mini = 1e9;
  for (int s1 = 0; s1 <= totsum / 2; s1++)
  {
    if (dp[n - 1][s1] == true)
    {
      int s2 = totsum - s1;
      mini = min(mini, abs(s1 - s2));
    }
  }

  cout << "Min Subset Sum Difference: " << mini << endl;
}