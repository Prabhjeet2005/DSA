#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
  vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}}; // Output  -> 21
  int n = path.size();                                // Row Size
  int m = path[0].size();                             // Col Size

  vector<int> prev(m, -1);
  for (int row = 0; row < n; row++)
  {
    vector<int> curr(m, -1);
    for (int col = 0; col < m; col++)
    {
      if (row == 0 && col == 0)
      {
        curr[0] = path[row][col];
      }
      else
      {
        int left = 1e9, up = 1e9;
        if (row > 0)
        {
          up = path[row][col] + prev[col];
        }
        if (col > 0)
        {
          left = path[row][col] + curr[col - 1];
        }
        curr[col] = min(left, up);
      }
    }
    prev = curr;
  }
  cout << "Min Path Sum: " << prev[m - 1] << endl;
}