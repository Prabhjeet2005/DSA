#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
  vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}}; // Output  -> 21
  int n = path.size();                                // Row Size
  int m = path[0].size();                             // Col Size

  vector<vector<int>> dp(n, vector<int>(m, -1));

  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      if (row == 0 && col == 0)
      {
        dp[0][0] = path[row][col];
      }
      else
      {
        int left = INT_MAX, up = INT_MAX;
        if (row > 0)
        {
          up = dp[row - 1][col];
        }
        if (col > 0)
        {
          left = dp[row][col - 1];
        }
        dp[row][col] = path[row][col] + min(left, up);
      }
    }
  }

  cout << "Min Path Sum: " << dp[n - 1][m - 1] << endl;
}