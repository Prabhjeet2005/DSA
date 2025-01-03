#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topoSort(vector<pair<int, int>> &edges, vector<int> &ans)
{
  vector<vector<int>> adj(4);
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  vector<int> indegree(4);
  for (auto i : adj)
  {
    for (auto j : i)  //Direct Element
    {
      indegree[j]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < 4; i++) // 4 are no of vertices
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    ans.push_back(front);

    for (auto neighbour : adj[front])
    {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0)
      {
        q.push(neighbour);
      }
    }
  }
}
int main()
{
  vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
  vector<int> ans;

  topoSort(edges, ans);

  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}