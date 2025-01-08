#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void makeSet(vector<int> &parent, int n)
{
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }
}

int findParent(vector<int> &parent, int node)
{
  if (parent[node] == node)
  {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void setUnion(vector<int> &parent, vector<int> &rank, int u, int v)
{
  u = findParent(parent, u);
  v = findParent(parent, v);

  if (rank[u] < rank[v])
  {
    parent[u] = v;
    rank[v]++;
  }
  else if (rank[u] > rank[v])
  {
    parent[v] = u;
    rank[u]++;
  }
  else{
    parent[u] = v;
    rank[v]++;
  }
}

bool cmp(vector<int> &a, vector<int> &b)
{
  return a[2] < b[2];
}

int Mst(vector<vector<int>> &edges, int n)
{
  vector<int> parent(n, -1);
  vector<int> rank(n, 0);

  makeSet(parent, n);

  int totalWt = 0;
  sort(edges.begin(), edges.end(), cmp);

  for (int i = 0; i < edges.size(); i++)
  {
    int u = findParent(parent, edges[i][0] - 1);
    int v = findParent(parent, edges[i][1] - 1);
    int wt = edges[i][2];

    if (u != v)
    {
      setUnion(parent, rank, u, v);
      totalWt += wt;
    }
  }
  return totalWt;
}

int main()
{
  vector<vector<int>> edges = {{1, 4, 1}, {1, 2, 2}, {2, 3, 3}, {2, 4, 3}, {1, 5, 4}, {3, 4, 5}, {2, 6, 7}, {3, 6, 8}, {4, 5, 9}};
  int n = 6;
  cout << "Weight of MST: " << Mst(edges, n) << endl;
}