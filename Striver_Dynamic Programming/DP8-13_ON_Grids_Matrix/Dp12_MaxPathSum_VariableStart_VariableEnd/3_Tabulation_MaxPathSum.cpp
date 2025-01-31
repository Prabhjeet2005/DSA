#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> mat = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int rowSize = mat.size();
  int colSize = mat[0].size();

  vector<vector<int>> dp(rowSize, vector<int>(colSize, -1));

  for (int i = 0; i < colSize; i++)
  {
    dp[0][i] = mat[0][i];
  }

  for (int i = 1; i < rowSize; i++)
  {
    for (int j = 0; j < colSize; j++)
    {
      int upRight = -1e9, upLeft = -1e9;
      int up = mat[i][j] + dp[i - 1][j];
      if (j + 1 < colSize)
      {
        upRight = mat[i][j] + dp[i - 1][j + 1];
      }
      if (j - 1 >= 0)
      {
        upLeft = mat[i][j] + dp[i - 1][j - 1];
      }
      dp[i][j] = max(up, max(upRight, upLeft));
    }
  }

  int maxi = -1e9;
  for (int i = 0; i < colSize; i++)
  {
    maxi = max(maxi, dp[rowSize - 1][i]);
  }
  cout << "Max Path Sum: " << maxi << endl;
}