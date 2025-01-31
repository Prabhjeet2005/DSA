#include <iostream>
#include <vector>
using namespace std;

int totalUniquePath(int row, int col, vector<vector<int>> &dp)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }
  int left = totalUniquePath(row, col - 1, dp);
  int up = totalUniquePath(row - 1, col, dp);

  return dp[row][col] = left + up;
}

int main()
{
  int m = 3;
  int n = 2;

  vector<vector<int>> dp(m, vector<int>(n, -1));

  cout << "Total Unique Paths: " << totalUniquePath(m - 1, n - 1, dp) << endl;
}