#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int v, int e, int src, int dest)
{
  unordered_map<int, list<int>> adjList;
  for (int i = 0; i < e; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  queue<int> q;
  unordered_map<int, int> parent;
  unordered_map<int, bool> visited;

  visited[src] = true;
  parent[src] = -1;
  q.push(src);

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    for (auto neighbour : adjList[front])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = true;
        parent[neighbour] = front;
        q.push(neighbour);
      }
    }
  }
  vector<int> ans;
  ans.push_back(dest);
  int currNode = dest;
  while (currNode != src)
  {
    currNode = parent[currNode];
    ans.push_back(currNode);
  }

  int s = 0, end = ans.size() - 1;
  while (s < end)
  {
    int t = ans[s];
    ans[s] = ans[end];
    ans[end] = t;
    s++;
    end--;
  }
  return ans;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {2, 5}, {5, 8}, {1, 3}, {3, 8}, {1, 4}, {4, 6}, {6, 7}, {7, 8}};
  int v = 8;
  int e = 9;
  int src = 1;
  int dest = 8;
  vector<int> ans = shortestPath(edges, v, e, src, dest);
  cout << "Shortest Path: ";
  for (auto i : ans)
  {
    cout << i << " ";
  }
  cout << endl;
}