#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>> mat = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int rowSize = mat.size();
  int colSize = mat[0].size();

  vector<int> prev(colSize);
  for (int i = 0; i < colSize; i++)
  {
    prev[i] = mat[0][i];
  }

  for (int i = 1; i < rowSize; i++)
  {
    vector<int> curr(colSize);
    for (int j = 0; j < colSize; j++)
    {
      int up = -1e9, upRight = -1e9, upLeft = -1e9;
      up = mat[i][j] + prev[j];
      if (j + 1 < colSize)
      {
        upRight = mat[i][j] + prev[j + 1];
      }
      if (j - 1 >= 0)
      {
        upLeft = mat[i][j] + prev[j - 1];
      }
      curr[j] = max(up, max(upLeft, upRight));
    }
    prev = curr;
  }

  int maxi = -1e9;
  for (int i = 0; i < prev.size(); i++)
  {
    maxi = max(maxi, prev[i]);
  }

  cout << "Maximum Path Sum: " << maxi << endl;
}