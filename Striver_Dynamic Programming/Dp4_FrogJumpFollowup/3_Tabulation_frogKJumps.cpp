#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size();
  int k = 2;

  vector<int> dp(n + 1, -1);

  dp[0] = 0;

  for (int i = 1; i < n; i++)
  {
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        int jump = dp[i - j] + abs(steps[i] - steps[i - j]);
        minSteps = min(minSteps, jump);
      }
    }
    dp[i] = minSteps;
  }

  cout << "Min Steps: " << dp.at(n-1) << endl;
}