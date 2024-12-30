/*
Problem statement
You are given a starting position for a rat which is stuck in a maze 
at an initial point (0, 0) (the maze can be thought of as a 
2-dimensional plane). 
The maze would be given in the form of a square matrix of 
order 'N' * 'N' where the cells with value 0 represent the maze’s 
blocked locations while value 1 is the open/available path that the 
rat can take to reach its destination. The rat's destination is 
at ('N' - 1, 'N' - 1). Your task is to find all the possible paths 
that the rat can take to reach from source to destination in the maze.
The possible directions that it can take to move in the maze are 
'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) 
i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

Note:
Here, sorted paths mean that the expected output should be in 
alphabetical order.
*/

#include<iostream>
#include<vector>
using namespace std;


bool isSafe(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &visited, int n)
{
  if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && visited[x][y] == 0)
  {
    return true;
  }
  return false;
}

void getPath(vector<vector<int>> &arr, vector<vector<int>> &visited,
             int x, int y, string path, vector<string> &ans, int n)
{
  if (x == n - 1 && y == n - 1)
  {
    ans.push_back(path);
    return;
  }
  visited[x][y] = 1;
  vector<int> directionx = {1, 0, 0, -1};
  vector<int> directiony = {0, -1, 1, 0};
  if (isSafe(x + directionx[0], y + directiony[0], arr, visited, n))
  {
    path.push_back('D');
    getPath(arr, visited, x + directionx[0], y + directiony[0], path, ans, n);
    path.pop_back();
  }
  if (isSafe(x + directionx[1], y + directiony[1], arr, visited, n))
  {
    path.push_back('L');
    getPath(arr, visited, x + directionx[1], y + directiony[1], path, ans, n);
    path.pop_back();
  }
  if (isSafe(x + directionx[2], y + directiony[2], arr, visited, n))
  {
    path.push_back('R');
    getPath(arr, visited, x + directionx[2], y + directiony[2], path, ans, n);
    path.pop_back();
  }
  if (isSafe(x + directionx[3], y + directiony[3], arr, visited, n))
  {
    path.push_back('U');
    getPath(arr, visited, x + directionx[3], y + directiony[3], path, ans, n);
    path.pop_back();
  }
  visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
  // Write your code here.
  vector<string> ans;
  if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
  {
    return ans;
  }
  vector<vector<int>> visited(arr.size(), vector<int>(arr.size(), 0));
  string path = "";
  //  DLRU
  int x = 0, y = 0;

  getPath(arr, visited, 0, 0, path, ans, n);
  return ans;
}

int main(){

  vector<vector<int>> arr = {{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};
  vector<vector<int>> visited(arr.size(), vector<int>(arr.size(), 0));
  if (arr[0][0] == 0)
  {
    return -1;
  }
    string path = "";
    vector<string>ans=searchMaze(arr, arr.size());

    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
}
