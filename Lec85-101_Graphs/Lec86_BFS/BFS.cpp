#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void createAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges)
{
  for (auto i : edges)
  {
    int u = i.first;
    int v = i.second;
    adjList[u].insert(v);
  }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited,
         vector<int> &ans, int i)
{
  queue<int> q;
  q.push(i);
  visited[i] = true;

  while (!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    ans.push_back(frontNode);

    for (int neighbours : adjList[frontNode])
    {
      if (!visited[neighbours])
      {
        q.push(neighbours);
        visited[neighbours] = true;
      }
    }
  }
}

vector<int> getAnsBfs(vector<pair<int, int>> edges)
{
  vector<int> ans;
  unordered_map<int, set<int>> adjList;
  createAdjList(adjList, edges);

  unordered_map<int, bool> visited;
  for (int i = 0; i < adjList.size(); i++)
  {
    visited[i] = false;
  }

  for (int i = 0; i < 1; i++)
  {
    if (!visited[i])
    {
      bfs(adjList, visited, ans, i);
    }
  }
  return ans;
}

int main()
{
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 7}, {2, 5}, {3, 6}};
  vector<int> ans;
  ans = getAnsBfs(edges);
  cout << "BFS: ";
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}