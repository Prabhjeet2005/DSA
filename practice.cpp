#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> triangle = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
  int n = triangle.size();

  // Initialize prev with the last row of the triangle
  vector<int> prev(triangle[n - 1]);

  // Iterate from second last row to the top
  for (int i = n - 2; i >= 0; i--)
  {
    vector<int> curr(i + 1); // Current row size is i + 1

    // Process each element in the current row
    for (int j = 0; j <= i; j++)
    {
      // Calculate the minimum path sum for each element
      int down = triangle[i][j] + prev[j];
      int downRight = triangle[i][j] + prev[j + 1];
      curr[j] = min(down, downRight);
    }

    // Update prev to store the current row's values
    prev = curr;
  }

  // The minimum path sum is now stored in prev[0]
  cout << "Min Path Sum: " << prev[0] << endl;
}
