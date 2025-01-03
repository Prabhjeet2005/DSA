#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void cycleDetectionBfs(vector<pair<int, int>> &edges, bool &ans, int v, int e)
{
  vector<vector<int>> adj(v);
  for (int i = 0; i < e; i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  vector<int> indegree(v);
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      indegree[adj[i][j]]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  int cnt = 0;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    cnt++;
    for (auto neighbour : adj[front])
    {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0)
      {
        q.push(neighbour);
      }
    }
  }

  if (cnt == v)
  {
    ans = false;
    return;
  }
  ans = true;
}

int main()
{
  vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
  bool ans;
  int v = 4;
  int e = 4;

  cycleDetectionBfs(edges, ans, v, e);

  cout << "Cycle? : " << ans << endl;
}