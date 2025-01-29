#include <iostream>
#include <vector>
using namespace std;

int triangleMinPathSum(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &triangle)
{
  if (row == triangle.size() - 1)
  {
    return triangle[row][col];
  }

  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int down = triangle[row][col] + triangleMinPathSum(row + 1, col, dp, triangle);
  int downRight = triangle[row][col] + triangleMinPathSum(row + 1, col + 1, dp, triangle);

  return dp[row][col] = min(down, downRight);
}

int main()
{
  vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
  int n = triangle.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));

  cout << "Min Path Sum: " << triangleMinPathSum(0, 0, dp, triangle) << endl;
}