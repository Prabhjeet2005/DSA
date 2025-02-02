#include <iostream>
#include <vector>
using namespace std;
int totalUniqueUnblockedPath(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &path)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }
  if (path[row][col] == -1)
  {
    return 0;
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int left = totalUniqueUnblockedPath(row, col - 1, dp, path);
  int up = totalUniqueUnblockedPath(row - 1, col, dp, path);

  return dp[row][col] = left + up;
}

int main()
{
  vector<vector<int>> path = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};

  int m = path.size();
  int n = path[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  cout << "Total Unique Unblocked Paths: " << totalUniqueUnblockedPath(m - 1, n - 1, dp, path) << endl;
}