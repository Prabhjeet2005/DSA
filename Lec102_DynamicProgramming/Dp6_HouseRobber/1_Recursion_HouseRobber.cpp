#include <iostream>
#include <vector>
using namespace std;

int maxNonAdjSum(int n, vector<int> &houses)
{
  if (n == 0)
  {
    return houses[0];
  }
  if (n < 0)
  {
    return 0;
  }

  int pick = houses[n] + maxNonAdjSum(n - 2, houses);
  int notPick = 0 + maxNonAdjSum(n - 1, houses);

  return max(pick, notPick);
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
  int ans1 = maxNonAdjSum(temp1.size() - 1, temp1);
  int ans2 = maxNonAdjSum(temp2.size() - 1, temp2);

  int ans = max(ans1, ans2);
  cout << "Max Non Adj Sum: " << ans << endl;
}