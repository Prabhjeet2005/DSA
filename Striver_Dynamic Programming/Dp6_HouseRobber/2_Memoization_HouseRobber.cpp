#include <iostream>
#include <vector>
using namespace std;

int maxNonAdjSum(int n, vector<int> &arr, vector<int> &dp)
{
  if (n == 0)
  {
    return arr[0];
  }
  if (n < 0)
  {
    return 0;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  int pick = arr[n] + maxNonAdjSum(n - 2, arr, dp);
  int notPick = 0 + maxNonAdjSum(n - 1, arr, dp);

  return dp[n] = max(pick, notPick);
}

int main()
{
  vector<int> houses = {1, 3, 2, 1};
  int n = houses.size();

  vector<int> temp1;
  vector<int> temp2;

  for (int i = 0; i < n; i++)
  {
    if (i != 0)
    {
      temp2.push_back(houses[i]);
    }
    if (i != n - 1)
    {
      temp1.push_back(houses[i]);
    }
  }

  vector<int> dp1(n + 1, -1);
  vector<int> dp2(n + 1, -1);
  int ans1 = maxNonAdjSum(temp1.size() - 1, temp1, dp1);
  int ans2 = maxNonAdjSum(temp2.size() - 1, temp2, dp2);

  int ans = max(ans1, ans2);
  cout << "Max Non Adj Sum: " << ans << endl;
}