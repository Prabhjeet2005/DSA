#include <iostream>
#include <vector>
using namespace std;

int triangleMinPathSum(int row, int col, vector<vector<int>> &triangle)
{
  if (row == triangle.size() - 1)
  {
    return triangle[row][col];
  }
  // It Won't Go Out Of Bounds in column
  int down = triangle[row][col] + triangleMinPathSum(row + 1, col, triangle);
  int downRight = triangle[row][col] + triangleMinPathSum(row + 1, col + 1, triangle);

  return min(down, downRight);
}

int main()
{
  vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};

  cout << "\nMin Path Sum: " << triangleMinPathSum(0, 0, triangle) << endl;
}