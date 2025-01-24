#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minPathSum(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
  if (row == 0 && col == 0)
  {
    return grid[row][col];
  }
  if (row < 0 || col < 0)
  {
    return INT_MAX;
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int up = minPathSum(row - 1, col, dp, grid);
  int left = minPathSum(row, col - 1, dp, grid);

  return dp[row][col] = grid[row][col] + min(up, left);
}

int main()
{
  vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}}; // Output  -> 21
  int n = path.size();                                // Row Size
  int m = path[0].size();                             // Col Size

  vector<vector<int>> dp(n, vector<int>(m, -1));

  cout << "Min Path Sum: " << minPathSum(n - 1, m - 1, dp, path) << endl;
}