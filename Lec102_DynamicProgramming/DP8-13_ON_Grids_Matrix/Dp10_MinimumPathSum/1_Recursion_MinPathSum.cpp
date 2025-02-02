#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int minPathSum(int row, int col, vector<vector<int>> &grid)
{
  if (row == 0 && col == 0)
  {
    return grid[row][col];
  }
  if (row < 0 || col < 0)
  {
    return 1e9;
  }
  int up = grid[row][col] + minPathSum(row - 1, col, grid);
  int left = grid[row][col] + minPathSum(row, col - 1, grid);

  return min(up, left); // Min Path till now and then add the current path (Write grid[row][col] HERE)  [IMPORTANT]
}

int main()
{
  vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}}; // Output  -> 21
  int n = path.size();                                // Row Size
  int m = path[0].size();                             // Col Size

  cout << "Min Path Sum: " << minPathSum(n - 1, m - 1, path) << endl;
}