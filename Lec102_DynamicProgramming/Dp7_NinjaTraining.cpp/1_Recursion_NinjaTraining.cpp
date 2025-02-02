#include <iostream>
#include <vector>
using namespace std;

int maxPoints(int day, int last, vector<vector<int>> &points)
{
  if (day == 0)
  {
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
      if (i != last)
      {
        maxi = max(maxi, points[0][i]);
      }
    }
    return maxi;
  }

  int maxi = INT_MIN;
  for (int i = 0; i < 3; i++)
  {
    if (i != last)
    {
      int ans = points[day][i] + maxPoints(day - 1, i, points);
      maxi = max(ans, maxi);
    }
  }

  return maxi;
}

int main()
{
  //  OUTPUT -> 210
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int day = points.size(); // Control Days in Recursion Call

  cout << "Max Points: " << maxPoints(day - 1, 3, points) << endl;
}