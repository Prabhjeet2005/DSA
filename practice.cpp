#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int minPathSum(int row, int col, vector<vector<int>> &grid)
{
  if (row == 0 && col == 0)
  {
    return grid[row][col];
  }
  if (row < 0 || col < 0)
  {
    return INT_MAX; // Return a large value to avoid invalid paths
  }
  int up = minPathSum(row - 1, col, grid);
  int left = minPathSum(row, col - 1, grid);

  return grid[row][col] + min(up, left);
}

int main()
{
  vector<vector<int>> path = {{5, 9, 6}, {11, 5, 2}}; // Expected output -> 21
  int n = path.size();                                // Row size
  int m = path[0].size();                             // Column size

  cout << "Min Path Sum: " << minPathSum(n - 1, m - 1, path) << endl;
}
