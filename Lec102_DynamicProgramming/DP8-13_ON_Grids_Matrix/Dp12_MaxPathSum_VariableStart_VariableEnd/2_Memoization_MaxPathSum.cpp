#include <iostream>
#include <vector>
using namespace std;

int maxPathSum(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &path)
{
  if (col < 0 || col >= path[0].size())
  {
    return -1e9;
  }
  if (row == 0)
  {
    return path[row][col];
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int up = path[row][col] + maxPathSum(row - 1, col, dp, path);
  int upLeft = path[row][col] + maxPathSum(row - 1, col - 1, dp, path);
  int upRight = path[row][col] + maxPathSum(row - 1, col + 1, dp, path);

  return max(up, max(upLeft, upRight));
}

int main()
{
  vector<vector<int>> mat = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int rowSize = mat.size();
  int colSize = mat[0].size();

  vector<vector<int>> dp(rowSize, vector<int>(colSize, -1));

  int maxi = -1e9;
  for (int i = 0; i < colSize; i++)
  {
    int ans = maxPathSum(rowSize - 1, i, dp, mat);
    maxi = max(ans, maxi);
  }
  cout << "Maximum Path Sum: " << maxi << endl;
}