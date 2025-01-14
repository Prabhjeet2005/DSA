#include <iostream>
#include <vector>
using namespace std;

int minCost(int n, vector<int> &dp, vector<int> &steps)
{
  if (n == 0)
  {
    return 0;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  int right = INT_MAX;
  int left = minCost(n - 1, dp, steps) + abs(steps[n - 1] - steps[n]);

  if (n > 1)
  {
    right = minCost(n - 2, dp, steps) + abs(steps[n - 2] - steps[n]);
  }
  return dp[n] = min(left, right);
}

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size();
  vector<int> dp(n, -1);

  cout << minCost(n - 1, dp, steps) << endl;
}