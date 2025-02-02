#include <iostream>
#include <vector>
using namespace std;

int nonAdjSum(int n, vector<int> &arr, vector<int> &dp)
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
  int pick = arr[n] + nonAdjSum(n - 2, arr, dp);
  int notPick = 0 + nonAdjSum(n - 1, arr, dp);

  return dp[n] = max(pick, notPick);
}

int main()
{
  vector<int> arr = {2, 1, 4, 9}; // Output -> 11
  int n = arr.size();
  vector<int> dp(n + 1, -1);

  cout << nonAdjSum(n - 1, arr, dp) << endl;
}