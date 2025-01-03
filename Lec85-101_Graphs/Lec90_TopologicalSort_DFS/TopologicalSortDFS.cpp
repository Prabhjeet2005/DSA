#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void topoSort(vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited, int src)
{
  visited[src] = true;

  for (auto neighbour : adj[src])
  {
    if (!visited[neighbour])
    {
      topoSort(adj, s, visited, neighbour);
    }
  }
  s.push(src);
}

void topologicalSort(vector<vector<int>> &edges, vector<int> &ans)
{
  vector<vector<int>> adj(edges.size());

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
  }
  stack<int> s;
  int n = 4;
  vector<bool> visited(4);
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      topoSort(adj, s, visited, i);
    }
  }
  while (!s.empty())
  {
    ans.push_back(s.top());
    s.pop();
  }
}

int main()
{
  vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
  vector<int> ans;

  topologicalSort(edges, ans);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}