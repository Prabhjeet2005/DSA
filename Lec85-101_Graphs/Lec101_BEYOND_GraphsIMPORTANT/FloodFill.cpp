#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &ans, vector<vector<int>> &flood, int srcRow,
         int srcCol, vector<int> &directionx, vector<int> &directiony, 
         int initialColor, int newColor)
{
  ans[srcRow][srcCol] = newColor;
  int n = ans.size();
  int m = ans[0].size();

  for (int i = 0; i < 4; i++)
  {
    int nrow = srcRow + directionx[i];
    int ncol = srcCol + directiony[i];
    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
    ans[nrow][ncol] != newColor && ans[nrow][ncol] == initialColor)
    {
      dfs(ans, flood, nrow, ncol, directionx, directiony, initialColor, newColor);
    }
  }
}

vector<vector<int>> floodFill(vector<vector<int>> &flood, int srcRow, int srcCol, int newColor)
{
  vector<vector<int>> ans = flood;

  int initialColor = flood[srcRow][srcCol];
  vector<int> directionx = {0, -1, 0, 1}; // LURD
  vector<int> directiony = {-1, 0, 1, 0}; // LURD

  dfs(ans, flood, srcRow, srcCol, directionx, directiony, initialColor, newColor);

  return ans;
}

int main()
{
  vector<vector<int>> flood = {{1, 1, 1}, {2, 2, 0}, {2, 2, 2}};
  int srcRow = 2;
  int srcCol = 0;
  int newColor = 3;
  vector<vector<int>> ans = floodFill(flood, srcRow, srcCol, newColor);

  for (auto row : ans)
  {
    for (auto col : row)
    {
      cout << col << " ";
    }
    cout << endl;
  }
}