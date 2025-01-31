#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
  int n = triangle.size();

  vector<vector<int>> dp(n, vector<int>(n, -1));

  // Base Case
  for (int j = 0; j < n; j++)
  {
    dp[n - 1][j] = triangle[n - 1][j];
  }
  
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = 0; j <= i; j++)
    {
      int down = triangle[i][j] + dp[i + 1][j];
      int downRight = triangle[i][j] + dp[i + 1][j + 1];
      dp[i][j] = min(down, downRight);
    }
  }

  cout << "Min Path Sum: " << dp[0][0] << endl;
}