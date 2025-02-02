#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {2, 1, 4, 9}; // Output -> 11
  int n = arr.size();             // Adjust Later
  vector<int> dp(n + 1, -1);

  dp[0] = arr[0];
  for (int i = 1; i < n; i++)
  {
    int pick = arr[i];
    if (i - 2 >= 0)
    {
      pick = arr[i] + dp[i - 2];
    }
    int notPick = 0 + dp[i - 1];

    dp[i] = max(pick, notPick);
  }

  cout << "Max Non Adj Sum: " << dp[n - 1] << endl;
}