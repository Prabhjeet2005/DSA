#include <iostream>
#include <vector>
using namespace std;

int totalUniqueUNBLOCKEDPaths(int row, int col, vector<vector<int>> &path)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }
  if (path[row][col] == -1)
  {
    return 0;
  }

  int left = totalUniqueUNBLOCKEDPaths(row, col - 1, path);
  int up = totalUniqueUNBLOCKEDPaths(row - 1, col, path);

  return left + up;
}

int main()
{
  vector<vector<int>> path = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
  int m = path.size();
  int n = path[0].size();

  if(path[0][0]==-1 || path[m-1][n-1]==-1){
    cout << "Invalid"<<endl;
  }

  cout << "Total Unique UnBlocked Paths: " << totalUniqueUNBLOCKEDPaths(m - 1, n - 1, path) << endl;
}