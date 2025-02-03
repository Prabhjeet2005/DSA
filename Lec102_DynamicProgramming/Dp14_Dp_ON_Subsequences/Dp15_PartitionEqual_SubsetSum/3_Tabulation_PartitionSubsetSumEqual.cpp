#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  int n = arr.size();

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 != 0)
  {
    cout << "Subset Doesnt Exist";
  }
  else
  {

    vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));
    for (int i = 0; i < n; i++)
    {
      dp[i][0] = true;
    }
    if (arr[0] <= sum / 2)
    {
      dp[0][arr[0]] = true;
    }

    for (int index = 1; index < n; index++)
    {
      for (int target = 1; target <= sum / 2; target++)
      {
        bool notPick = dp[index - 1][target];
        bool pick = false;
        if (arr[index] <= target)
        {
          pick = dp[index - 1][target - arr[index]];
        }
        dp[index][target] = pick || notPick;
      }
    }
    cout << "Subset Exists or not: ";
    dp[n - 1][sum / 2] == 1 ? cout << "Yes\n" : cout << "No\n";
  }
}