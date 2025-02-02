#include <iostream>
#include <vector>
using namespace std;

// int f(int n, vector<int> &dp)
// {
//   if (n == 0)
//   {
//     return 1;
//   }
//   if (n == 1)
//   {
//     return 1;
//   }
//   if (dp[n] != -1)
//   {
//     return dp[n];
//   }
//   int one = f(n - 1, dp);
//   int two = f(n - 2, dp);

//   return dp[n] = one + two;
// }

int main()
{
  int n = 4;
  vector<int> dp(n + 1, -1);

  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++){
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n] << endl;
}