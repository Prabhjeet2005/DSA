#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
#include <stack>

using namespace std;

bool isCyclic(unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj, int src)
{
  unordered_map<int, int> parent;
  parent[src] = -1;
  visited[src] = true;
  stack<int> q;
  q.push(src);

  while (!q.empty())
  {
    int frontNode = q.top();
    q.pop();

    for (auto neighbour : adj[frontNode])
    {
      if (visited[neighbour] == true && neighbour != parent[frontNode])
      {
        return true;
      }
      else if (!visited[neighbour])
      {
        q.push(neighbour);
        parent[neighbour] = frontNode;
        visited[neighbour] = true;
      }
    }
  }
  return false;
}

void cycleUndirectedBFS(vector<vector<int>> edges, string &ans)
{
  unordered_map<int, bool> visited;
  unordered_map<int, set<int>> adj;

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].insert(v);
    adj[v].insert(u);
  }

  for (auto i : adj)
  {
    cout << i.first << " -> ";
    for (auto j : i.second)
    {
      cout << j << ", ";
    }
    cout << endl;
  }

  // Disconnected Componenets but i took 1
  if (!visited[4])
  {
    bool result = isCyclic(visited, adj, 4);
    if (result == true)
    {
      ans = "Yes";
      return;
    }
  }
  ans = "No";
}

int main()
{
  vector<vector<int>> edges = {{4, 5}, {5, 6}, {5, 7}, {7, 8}, {6, 8}, {8, 9}, {11, 12}};
  string ans;
  cycleUndirectedBFS(edges, ans);
  cout << "Is Cycle: " << ans << endl;
}