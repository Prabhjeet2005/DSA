#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int node, int parent, vector<int> &low, vector<int> &discovery,
         vector<bool> &ap, vector<bool> &visited, int &timer, unordered_map<int, vector<int>> &adj)
{
  visited[node] = true;
  low[node] = discovery[node] = timer++;
  int child = 0;
  for (auto neighbour : adj[node])
  {
    if (neighbour == parent)
    {
      continue;
    }
    if (!visited[neighbour])
    {
      dfs(neighbour, node, low, discovery, ap, visited, timer, adj);
      low[node] = min(low[node], discovery[neighbour]);
      if (low[neighbour] >= discovery[node] && parent != -1)
      {
        ap[node] = true;
      }
      child++;
    }
    else
    { // Back Edge
      low[node] = min(low[node], discovery[neighbour]);
    }
  }
  if (parent == -1 && child > 1)
  {
    ap[node] = true;
  }
}

vector<bool> ArticulationPoints(vector<pair<int, int>> &edges, int v, int e)
{
  unordered_map<int, vector<int>> adj(v);
  for (int i = 0; i < e; i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> ap(v, false);
  vector<bool> visited(v, false);
  int timer = 0;
  int parent = -1;
  vector<int> low(v, -1);
  vector<int> discovery(v, -1);

  for (int i = 0; i < v; i++)
  {
    dfs(i, parent, low, discovery, ap, visited, timer, adj);
  }

  return ap;
}

int main()
{
  // Print All Articulation Points
  vector<pair<int, int>> edges;
  edges.push_back({0, 3});
  edges.push_back({4, 3});
  edges.push_back({0, 4});
  edges.push_back({0, 1});
  edges.push_back({1, 2});
  int v = 5;
  int e = edges.size();

  vector<bool> ap = ArticulationPoints(edges, v, e);

  for (int i = 0; i < ap.size(); i++)
  {
    if (ap[i] != false)
    {
      cout << i << " ";
    }
  }
  cout << endl;
}