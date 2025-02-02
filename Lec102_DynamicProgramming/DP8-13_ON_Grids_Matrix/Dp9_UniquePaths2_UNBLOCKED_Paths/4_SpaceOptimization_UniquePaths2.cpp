#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> path = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
  int m = path.size();
  int n = path[0].size();

  if (path[m - 1][n - 1] == -1 || path[0][0] == -1)
  {
    cout << "Invalid" << endl;
  }
  vector<int> prev(n, -1);
  for (int row = 0; row < m; row++)
  {
    vector<int> curr(n, -1);
    for (int col = 0; col < n; col++)
    {
      if (row == 0 && col == 0)
      {
        curr[0] = 1;
      }
      else if (path[row][col] == -1)
      {
        curr[col] = 0; // If here -1 is assigned then give error(As No Path Exists so 0)
      }
      else
      {
        int up = 0, left = 0;
        if (row > 0)
        {
          up = prev[col];
        }
        if (col > 0)
        {
          left = curr[col - 1];
        }
        curr[col] = left + up;
      }
    }
    prev = curr;
  }
  cout << "Total Unblocked Paths: " << prev[n - 1] << endl;
}