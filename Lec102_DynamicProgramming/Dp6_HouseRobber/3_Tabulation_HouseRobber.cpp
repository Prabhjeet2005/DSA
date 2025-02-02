#include <iostream>
#include <vector>
using namespace std;

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

  vector<int> dp(n + 1, -1);
  dp[0] = houses[0];
  for (int i = 1; i < n; i++)
  {
    int pick = houses[i];
    if (i - 2 >= 0)
    {
      pick = houses[i] + dp[i - 2];
    }
    int notPick = 0 + houses[i - 1];

    dp[i] = max(pick, notPick);
  }

  vector<int> dp2(n + 1, -1);
  dp2[0] = houses[0];
  for (int i = 1; i < n; i++)
  {
    int pick = houses[i];
    if (i - 2 >= 0)
    {
      pick = houses[i] + dp2[i - 2];
    }
    int notPick = 0 + houses[i - 1];

    dp2[i] = max(pick, notPick);
  }
  cout << "Max Non Adj Sum: " << max(dp[n - 1], dp2[n - 1]) << endl;
}