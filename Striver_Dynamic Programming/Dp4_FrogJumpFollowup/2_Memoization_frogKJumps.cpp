#include <iostream>
#include <vector>

using namespace std;

int minCost(int n, vector<int> &steps, vector<int> &dp, int k)
{
  if (n == 0)
  {
    return 0;
  }
  int minSteps = INT_MAX;
  if (dp[n] != -1)
  {
    return dp[n];
  }
  for (int i = 1; i <= k; i++)
  {
    if (n - i >= 0)
    {
      int jump = minCost(n - i, steps, dp, k) + abs(steps[n] - steps[n - i]);
      minSteps = min(minSteps, jump);
    }
  }
  return dp[n] = minSteps;
}

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size();
  int k = 2;
  vector<int> dp(n + 1, -1);

  cout << "Min Cost: " << minCost(n - 1, steps, dp, k) << endl;
}