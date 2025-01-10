#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int node, stack<int> &stack, unordered_map<int, vector<int>> &adj, vector<bool>& visited)
{
  visited[node] = true;

  for (auto neighbour : adj[node])
  {
    if (!visited[neighbour])
    {
      dfs(neighbour, stack, adj, visited);
    }
  }
  stack.push(node);
}

void revDfs(int node, vector<bool> &visited, unordered_map<int, vector<int>> &transpose)
{
  visited[node] = true;

  for (auto neighbour : transpose[node])
  {
    if (!visited[neighbour])
    {
      revDfs(neighbour, visited, transpose);
    }
  }
}

int KosarajuSSC(vector<pair<int, int>> &edges, int v, int e)
{
  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < e; i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  // Topo Sort
  stack<int> stack;
  vector<bool> visited(v);

  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      dfs(i, stack, adj, visited);
    }
  }

  // Transpose
  unordered_map<int, vector<int>> transpose;
  for (int i = 0; i < v; i++)
  {
    visited[i] = false;
    for (auto j : adj[i])
    {
      transpose[j].push_back(i);
    }
  }

  // Calculate DFS on Topo Sorted Order
  int count = 0;
  while (!stack.empty())
  {
    int top = stack.top();
    stack.pop();
    if (!visited[top])
    {
      count++;
      revDfs(top, visited, transpose);
    }
  }
  return count;
}

int main()
{
  vector<pair<int, int>> edges;
  edges.push_back({0, 1});
  edges.push_back({1, 2});
  edges.push_back({2, 0});
  edges.push_back({1, 3});
  edges.push_back({3, 4});
  int v = 5;
  int e = edges.size();

  int ans = KosarajuSSC(edges, v, e);
  cout << "No. Of Strongly Connected Components: " << ans << endl;
}