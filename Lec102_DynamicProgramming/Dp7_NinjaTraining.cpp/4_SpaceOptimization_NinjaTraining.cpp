#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
  int n = points.size();

  vector<int> prev(4, -1);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++)
  {
    vector<int> temp(4, -1);
    for (int last = 0; last < 4; last++)
    {
      for (int i = 0; i < 3; i++)
      {
        if (i != last)
        {
          temp[last] = max(temp[last], points[day][i] + prev[i]);
        }
      }
    }
    prev = temp;
  }
  cout << "Max Points: " << prev[3] << endl;
}