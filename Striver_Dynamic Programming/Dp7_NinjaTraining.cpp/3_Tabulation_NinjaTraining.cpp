#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int n = points.size();

  vector<vector<int>> dp(n + 1, vector<int>(4, -1));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++)
  {
    for (int last = 0; last < 4; last++)
    {
      for (int i = 0; i < 3; i++)
      {
        if (i != last)
        {
          int ans = points[day][i] + dp[day - 1][i];
          dp[day][last] = max(dp[day][last], ans);  // Store in Current Day The adjacent Max Values
        }
      }
    }
  }
  cout << dp[n - 1][3] << endl;
}
