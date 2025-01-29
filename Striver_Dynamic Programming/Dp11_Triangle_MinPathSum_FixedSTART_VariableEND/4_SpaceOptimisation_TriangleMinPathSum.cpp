#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
  int n = triangle.size();

  vector<int> prev(n);
  for (int i = 0; i < n; i++)
  {
    prev[i] = triangle[n - 1][i];
  }

  for (int i = n - 2; i >= 0; i--)
  {
    vector<int> curr(i + 1);
    for (int j = 0; j <= i; j++)
    {
      int down = triangle[i][j] + prev[j];
      int downRight = triangle[i][j] + prev[j + 1];
      curr[j] = min(down, downRight);
    }
    prev = curr;
  }
  cout << "Min Path Sum: " << prev[0] << endl;
}