#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> path = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
  int m = path.size();
  int n = path[0].size();
  vector<vector<int>> dp(m, vector<int>(n, -1));

  if (path[m - 1][n - 1] == -1 || path[0][0] == -1)
  {
    cout << "Invalid" << endl;
  }

  for (int row = 0; row < m; row++)
  {
    for (int col = 0; col < n; col++)
    {
      if (row == 0 && col == 0)
      {
        dp[0][0] = 1;
      }
      else if (path[row][col] == -1)
      {
        dp[row][col] = 0; // If here -1 is assigned then give error(As No Path Exists so 0)
      }
      else
      {
        int up = 0, left = 0;
        if (row > 0)
        {
          up = dp[row - 1][col];
        }
        if (col > 0)
        {
          left = dp[row][col - 1];
        }
        dp[row][col] = left + up;
      }
    }
  }
  cout << "Total Unblocked Paths: " << dp[m - 1][n - 1] << endl;
}