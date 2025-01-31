#include <iostream>
#include <vector>
using namespace std;

int maxPathSum(int row, int col1, int col2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid)
{
  if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
  {
    return -1e9;
  }

  if (row == grid.size()-1)
  {
    if (col1 == col2)
    {
      return grid[row][col1];
    }
    else
    {
      return grid[row][col1] + grid[row][col2];
    }
  }

  if (dp[row][col1][col2] != -1)
  {
    return dp[row][col1][col2];
  }

  int maxi = -1e9;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (col1 == col2)
      {
        maxi = max(maxi, grid[row][col1] + maxPathSum(row+1, col1 + dj1, col2 + dj2, dp, grid));
      }
      else
      {
        maxi = max(maxi, grid[row][col1] + grid[row][col2] + maxPathSum(row+1, col1 + dj1, col2 + dj2, dp, grid));
      }
    }
  }

  return dp[row][col1][col2] = maxi;
}

int main()
{
  vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}}; // Output-> 21
  int rowSize = grid.size();
  int colSize = grid[0].size();

  vector<vector<vector<int>>> dp(rowSize, vector<vector<int>>(colSize, vector<int>(colSize, -1)));
  cout << "Maximum Path Sum By Two People: " << maxPathSum(0, 0, colSize - 1, dp, grid) << endl;
}