#include <iostream>
#include <vector>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
  for (int i = 0; i < n; i++)
  {
    parent[i] = i; // Self Loop
    rank[i] = 0;   // Initialize each rank = 0
  }
}

int findParent(vector<int> &parent, int node)
{
  if (parent[node] == node) // If Self Loop Found Means Parent
  {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]); // String Compression by parent[node]
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
  // Compare Ranks of Parent
  u = findParent(parent, u);
  v = findParent(parent, v);
  if (rank[u] < rank[v])
  {
    parent[u] = v;
    rank[v]++;
  }
  else if (rank[v] < rank[u])
  {
    parent[v] = u;
    rank[u]++;
  }
  else // Rank is Equal
  {
    parent[u] = v;
    rank[v]++;
  }
}

bool cmp(vector<int> &a, vector<int> &b)
{ // Custom Comparator As we need to find on what bases to sort edges array
  return a[2] < b[2];
}

int minSpanningTree(vector<vector<int>> &edges, int n)
{

  vector<int> parent(n);
  vector<int> rank(n);

  sort(edges.begin(), edges.end(), cmp); // On Basis of Weight with help of cmp

  makeSet(parent, rank, n);

  int totalWt = 0;

  for (int i = 0; i < edges.size(); i++)
  {
    int u = findParent(parent, edges[i][0] - 1);
    int v = findParent(parent, edges[i][1] - 1);
    int wt = edges[i][2];

    if (u != v)
    {
      totalWt += wt;
      unionSet(parent, rank, u, v);
    }
  }
  return totalWt;
}

int main()
{
  vector<vector<int>> edges = {{1, 4, 1}, {1, 2, 2}, {2, 3, 3}, {2, 4, 3}, {1, 5, 4}, {3, 4, 5}, {2, 6, 7}, {3, 6, 8}, {4, 5, 9}};
  int n = 6;
  cout << "Ans: " << minSpanningTree(edges, n);
}