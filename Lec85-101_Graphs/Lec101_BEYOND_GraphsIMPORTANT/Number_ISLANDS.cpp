#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &islands,
     vector<vector<bool>> &visited, int n, int m)
{
  visited[row][col] = true;
  queue<pair<int, int>> q;
  q.push({row, col});
  while (!q.empty())
  {
    auto front = q.front();
    row = front.first;
    col = front.second;
    q.pop();

    for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
    {
      for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
      {
        int nrow = row + deltaRow;
        int ncol = col + deltaCol;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            visited[nrow][ncol] == false && islands[nrow][ncol] == '1')
        {
          visited[nrow][ncol] = true;
          q.push({nrow, ncol});
        }
      }
    }
  }
}

int calcIslands(vector<vector<char>> &islands)
{
  int n = islands.size();
  int m = islands[0].size();

  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (!visited[i][j] && islands[i][j] == '1')
      {
        cnt++;
        bfs(i, j, islands, visited, n, m);
      }
    }
  }
  return cnt;
}

int main()
{
  vector<vector<char>> islands = {{'0', '1', '1', '0'},
                                 {'0', '1', '1', '0'},
                                 {'0', '0', '1', '0'},
                                 {'0', '0', '0', '0'},
                                 {'1', '1', '0', '1'}};

  int ans = calcIslands(islands);
  cout << "No. of Islands: " << ans << endl;
}