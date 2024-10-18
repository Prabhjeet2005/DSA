#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//TC =>O(4^n^2)
using namespace std;
bool isSafe(vector<vector<int>> &ques, vector<vector<int>> visited, int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n && (ques[x][y] == 1) && (visited[x][y] == 0)) // ques and visited must come at end
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve(vector<string> &ans, vector<vector<int>> &ques, vector<vector<int>> &visited,
           int x, int y, string path, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    int newx = x + 1;
    int newy = y;
    if (isSafe(ques, visited, newx, newy, n))
    {
        path.push_back('D'); // DOWN
        solve(ans, ques, visited, newx, newy, path, n);
        path.pop_back();
    }
    // LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(ques, visited, newx, newy, n))
    {
        path.push_back('L');
        solve(ans, ques, visited, newx, newy, path, n);
        path.pop_back();
    }

    // RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(ques, visited, newx, newy, n))
    {
        path.push_back('R');
        solve(ans, ques, visited, newx, newy, path, n);
        path.pop_back();
    }

    // UP
    newx = x - 1;
    newy = y;
    if (isSafe(ques, visited, newx, newy, n))
    {
        path.push_back('U');
        solve(ans, ques, visited, newx, newy, path, n);
        path.pop_back();
    }
    visited[x][y] = 0;
}

int main()
{
    vector<string> ans;
    vector<vector<int>> ques = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<vector<int>> visited(ques.size(), vector<int>(ques.size(), 0));
    if (ques[0][0] == 0)
    {
        return -1;
    }
    string path = "";
    int srcx = 0, srcy = 0;
    solve(ans, ques, visited, srcx, srcy, path, ques.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}