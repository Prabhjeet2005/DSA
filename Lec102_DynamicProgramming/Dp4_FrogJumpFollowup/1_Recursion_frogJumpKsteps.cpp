#include <iostream>
#include <vector>

using namespace std;

int minCost(int n, vector<int> &steps, int k)
{
  if (n == 0)
  {
    return 0;
  }
  int minSteps = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if (n - i >= 0)
    {
      int jump = minCost(n - i, steps, k) + abs(steps[n] - steps[n - i]);
      minSteps = min(minSteps, jump);
    }
  }
  return minSteps;
}

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int k = 2;
  int n = steps.size() - 1;

  cout << "Min Cost: " << minCost(n, steps, k) << endl;
}