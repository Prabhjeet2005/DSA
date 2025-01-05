#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <limits.h>
#include <unordered_map>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adj;
  void addEdge(int u, int v, int weight)
  {
    adj[u].push_back({v, weight});
  }
  void printAdj()
  {
    for (auto i : adj)
    {
      cout << i.first << " -> ";
      for (auto j : i.second)
      {
        cout << "(" << j.first << ", " << j.second << ")" << " , ";
      }
      cout << endl;
    }
  }

  void topoSortDfs(unordered_map<int, bool> &visited, stack<int> &s, int node)
  {
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour.first])
      {
        topoSortDfs(visited, s, neighbour.first);
      }
    }
    s.push(node); // Topological Sort
  }

  void getShortestPath(stack<int> &s, vector<int> &distance, int src)
  {
    distance[src] = 0;

    while (!s.empty())
    {
      int top = s.top();
      s.pop();

      if (distance[top] != INT_MAX)
      {
        for (auto i : adj[top])
        {
          if (distance[top] + i.second < distance[i.first]) // distance[top]->till top how much distance, i.second->weight of top
          {
            distance[i.first] = distance[top] + i.second;
          }
        }
      }
    }
  }
};

int main()
{
  Graph g;
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  int n = 6;
  stack<int> s;
  unordered_map<int, bool> visited;
  for (int i = 0; i < n; i++)
  {
    g.topoSortDfs(visited, s, i);
  }

  vector<int> distance(n);
  for (int i = 0; i < n; i++)
  {
    distance[i] = INT_MAX;
  }

  int src = 1;
  g.getShortestPath(s, distance, src);

  cout << "Answer: ";
  for (auto i : distance)
  {
    cout << i << " ";
  }
  cout << endl;
}