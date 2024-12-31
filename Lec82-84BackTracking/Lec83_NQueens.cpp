#include <iostream>
#include <vector>
using namespace std;

void addToAns(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
  vector<int> temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      temp.push_back(board[i][j]);
    }
  }
  ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
  int tempx = row;
  int tempy = col;
  while (tempy >= 0)
  { // Row Check
    if (board[tempx][tempy] == 1)
    {
      return false;
    }
    tempy--;
  }
  tempx = row;
  tempy = col;
  while (tempx >= 0 && tempy >= 0)
  { // Upper Diagonal
    if (board[tempx][tempy] == 1)
    {
      return false;
    }
    tempx--;
    tempy--;
  }
  tempx = row;
  tempy = col;
  while (tempx < n && tempy >= 0)
  {//Lower Diagonal
    if (board[tempx][tempy] == 1)
    {
      return false;
    }
    tempx++;
    tempy--;
  }
  return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
  if (col == n)
  {
    addToAns(ans, board, n);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    int x = i, y = col;
    if (isSafe(x, y, ans, board, n))
    {
      board[x][y] = 1;
      solve(y + 1, ans, board, n);
      board[x][y] = 0;
    }
  }
}

vector<vector<int>> NQueens(int n)
{
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));

  solve(0, ans, board, n);

  return ans;
}

int main()
{
  vector<vector<int>> ans;
  int n = 4;

  ans = NQueens(n);

  cout << "Printing Answer\n";
  for (auto i : ans)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}