#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <list>

using namespace std;
vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
  // Write your code here.
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < m; i++)
  {
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> key(n, INT_MAX);
  vector<bool> mst(n, false);
  vector<int> parent(n, -1);

  key[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, key[0]});

  while (!pq.empty())
  {
    pair<int, int> u = pq.top();
    pq.pop();

    mst[u.first] = true;

    for (auto neighbour : adj[u.first])
    {
      int v = neighbour.first;
      int w = neighbour.second;
      if (mst[v] == false && w < key[v])
      {
        parent[v] = u.first;
        key[v] = w;
        pq.push({v, key[v]});
      }
    }
  }
  vector<pair<pair<int, int>, int>> ans;
  for (int i = 1; i < n; i++)
  {
    ans.push_back({{parent[i], i}, key[i]});
  }
  return ans;
}

int main()
{
  vector<pair<pair<int, int>, int>> e = {{{0, 3}, 6}, {{0, 1}, 2}, {{3, 1}, 8}, {{1, 4}, 5}, {{1, 2}, 3}, {{4, 2}, 7}};
  int vertices = 5;
  int edges = 6;
  int src = 0;
  vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(vertices, edges, e);
  for (auto i : ans)
  {
    cout << i.first.first << ", " << i.first.second << " , " << i.second;
    cout << endl;
  }
}

// vector<vector<int>> prim(vector<vector<int>> &e, int vertices, int edges, int src)
// {
//   unordered_map<int, list<pair<int, int>>> adj;
//   for (int i = 0; i < edges; i++)
//   {
//     int u = e[i][0];
//     int v = e[i][1];
//     int w = e[i][2];
//     adj[u].push_back({v, w});
//     adj[v].push_back({u, w});
//   }

//   vector<int> key(vertices, INT_MAX);
//   vector<bool> mst(vertices, false);
//   vector<int> parent(vertices, -1);

//   key[src] = 0;

//   for (int i = 0; i < vertices; i++)
//   {
//     int mini = INT_MAX;
//     int u;
//     for (int j = 0; j < vertices; j++)
//     {
//       if (mst[j] == false && key[j] < mini)
//       {
//         mini = key[j];
//         u = j;
//       }
//     }

//     mst[u] = true;
//     for (auto neighbour : adj[u])
//     {
//       int v = neighbour.first;
//       int w = neighbour.second;
//       if (mst[v] == false && w < key[v])
//       {
//         parent[v] = u;
//         key[v] = w;
//       }
//     }
//   }
//   vector<vector<int>> result;
//   for (int i = 1; i < vertices; i++)
//   {
//     result.push_back({parent[i], i, key[i]});
//   }
//   return result;
// }