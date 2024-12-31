#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudoku[i][col] == val)
    {
      return false;
    }
    if (sudoku[row][i] == val)
    {
      return false;
    }
    if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
    {
      return false;
    }
  }
  return true;
}

bool solve(vector<vector<int>> &sudoku)
{
  for (int row = 0; row < 9; row++)
  {
    for (int col = 0; col < 9; col++)
    {
      if (sudoku[row][col] == 0)
      {
        for (int i = 1; i <= 9; i++)
        {
          if (isSafe(row, col, sudoku, i))
          {
            sudoku[row][col] = i;
            bool furtherPossible = solve(sudoku);
            if (furtherPossible)
            {
              return true;
            }
            else
            {
              sudoku[row][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main()
{
  vector<vector<int>> sudoku = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};

  solve(sudoku);

  for (auto i : sudoku)
  {
    for (auto j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}