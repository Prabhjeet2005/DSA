#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int timer, int parent, vector<int> &low, vector<int> &discovery,
         vector<bool> &visited, vector<vector<int>> &adj, vector<vector<int>> &result)
{
  visited[node] = true;
  low[node] = discovery[node] = timer++;

  for (auto neighbour : adj[node])
  {
    if (neighbour == parent)
    {
      continue;
    }
    if (!visited[neighbour])
    {
      dfs(neighbour, timer, node, low, discovery, visited, adj, result);
      low[node] = min(low[node], low[neighbour]); // another Path access(neighbour)?

      if (low[neighbour] > discovery[node])
      {
        result.push_back({node, neighbour});
      }
    }
    else
    {
      // BackEdge
      low[node] = min(low[node], discovery[neighbour]);
    }
  }
}

vector<vector<int>> findBridge(vector<vector<int>> &edges, int n)
{
  vector<vector<int>> adj(n);
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0] - 1;
    int v = edges[i][1] - 1;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int timer = 0;
  vector<int> low(n, -1);
  vector<int> discovery(n, -1);
  vector<bool> visited(n);
  int parent = -1;

  vector<vector<int>> result;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(i, timer, parent, low, discovery, visited, adj, result);
    }
  }
  return result;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {2, 4}, {4, 3}, {1, 3}, {2, 3}, {3, 5}};
  int n = 5;
  vector<vector<int>> ans = findBridge(edges, n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i][0] + 1 << "---" << ans[i][1] + 1;
    cout << endl;
  }
}