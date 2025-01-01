#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

void getDFS(unordered_map<int, set<int>> adjList, unordered_map<int, bool> visited,
            vector<int> &ans, int n)
{

  stack<int> s;
  s.push(n);
  visited[n] = true;

  while (!s.empty())
  {
    int top = s.top();
    s.pop();
    ans.push_back(top);

    for (auto i : adjList[top])
    {
      if (!visited[i])
      {
        s.push(i);
        visited[i] = true;
      }
    }
  }
}

void dfs(vector<pair<int, int>> edges, vector<int> &ans)
{
  unordered_map<int, set<int>> adjList;
  unordered_map<int, bool> visited;

  for (auto i : edges)
  {
    int u = i.first;
    int v = i.second;

    adjList[u].insert(v);
    adjList[v].insert(u);
  }

  for (int i = 0; i < 1; i++)
  { // for Loop to (include Disconnected Components) then 
    // traverse till n which is the number of total vertices given
    if (!visited[i])
    {
      getDFS(adjList, visited, ans, i);
    }
  }
}

int main()
{
  // vector<pair<int, int>> edges;
  // cout << "Enter No. of Vertices and Edges: ";
  // int n, m;
  // cin >> n >> m;
  // for (int i = 0; i < m; i++)
  // {
  //   cout << "Enter 2 Edges: ";
  //   int u, v;
  //   cin >> u >> v;
  //   edges.push_back({u, v});
  // }
  vector<pair<int, int>> edges = {{0, 4}, {4, 2}, {2, 3}, {3, 5}, {5, 1}};

  vector<int> ans;
  dfs(edges, ans);
  cout << "DFS: ";
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}