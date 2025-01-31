#include <iostream>
#include <vector>
using namespace std;

int maxPathSum(int row, int col1, int col2, vector<vector<int>> &grid)
{

  if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
  {
    return -1e9;
  }

  if (row == grid.size() - 1)
  {
    if (col1 == col2) // End Up At Same Cell
    {
      return grid[row][col1];
    }
    else  //End up At Different Cells
    {
      return grid[row][col1] + grid[row][col2];
    }
  }

  int maxi = -1e9;
  for (int dj1 = -1; dj1 <= 1; dj1++)
  {
    for (int dj2 = -1; dj2 <= 1; dj2++)
    {
      if (col1 == col2) // Same Cell
      {
        maxi = max(maxi, grid[row][col1] + maxPathSum(row + 1, col1 + dj1, col2 + dj2, grid));
      }
      else  // Different Cells
      {
        maxi = max(maxi, grid[row][col1] + grid[row][col2] + maxPathSum(row + 1, col1 + dj1, col2 + dj2, grid));
      }
    }
  }
  return maxi;
}

int main()
{
  vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}}; // Output-> 21
  int rowSize = grid.size();
  int colSize = grid[0].size();

  cout << "Maximum Path Sum by Two People: " << maxPathSum(0, 0, colSize - 1, grid) << endl;
}