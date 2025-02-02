#include <iostream>
#include <vector>
using namespace std;

int maxPoints(int days, int last, vector<vector<int>> &dp, vector<vector<int>> &points)
{
  if(days==0){
    int maxi = INT_MIN;
    for (int i = 0; i<3; i++){
      if(i!=last){
        maxi = max(maxi, points[0][i]);
      }
    }
    return dp[days][last] = maxi;
  }

  if(dp[days][last] != -1){
    return dp[days][last];
  }

  int maxi = INT_MIN;
  for (int i = 0; i<3; i++){
    if(i!=last){
      int ans = points[days][i] + maxPoints(days - 1, i, dp, points);
      maxi = max(maxi, ans);
    }
  }
  return dp[days][last] = maxi;
}

int main()
{
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int days = points.size();

  vector<vector<int>> dp(days + 1, vector<int>(4, -1));
  cout << "Max Points: " << maxPoints(days - 1, 3, dp, points) << endl;
}