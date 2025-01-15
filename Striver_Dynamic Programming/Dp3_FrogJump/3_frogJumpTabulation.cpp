#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size();
  vector<int> dp(n + 1, -1);

  dp[0] = 0;
  dp[1] = abs(steps[0] - steps[1]);

  for (int i = 2; i < n; i++)
  {
    dp[i] = min(dp[i - 1] + abs(steps.at(i) - steps[i - 1]), dp[i - 2] + abs(steps.at(i) - steps[i - 2]));
  }
  cout << "Min Cost: " << dp[n - 1] << endl;
}