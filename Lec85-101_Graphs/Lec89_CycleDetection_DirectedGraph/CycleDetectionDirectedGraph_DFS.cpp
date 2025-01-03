#include <iostream>
#include <stack>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

bool isCycle(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited,
             unordered_map<int, bool> &dfsvisited, int src)
{

  visited[src] = true;
  dfsvisited[src] = true;

  for (auto neighbour : adj[src])
  {
    if (!visited[neighbour])
    {
      bool ans = isCycle(adj, visited, dfsvisited, neighbour);
      if (ans)
      {
        return true;
      }
    }
    else if (visited[neighbour] == true && dfsvisited[neighbour])
    {
      return true;
    }
  }
  dfsvisited[src] = false;
  return false;
}

void cycleDetect(vector<vector<int>> &edges, bool &ans)
{
  unordered_map<int, set<int>> adj;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsvisited;

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].insert(v);
  }

  for (int i = 1; i <= 10; i++)
  {
    if (!visited[i])
    {
      if (isCycle(adj, visited, dfsvisited, i))
      {
        ans = true;
        return;
      }
    }
  }
  ans = false;
  return;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
  bool ans = false;
  cycleDetect(edges, ans);
  cout << "Is Cycle? : " << ans << endl;
}