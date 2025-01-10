#include <iostream>
#include <vector>
using namespace std;

int bellmanFord(vector<vector<int>> edges, int src, int dest, int v)
{
  vector<int> distance(v+1, INT_MAX);
  distance[src] = 0;
  for (int j = 0; j < v - 1; j++)
  {
    int flag = 0;
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0] ;
      int v = edges[i][1] ;
      int wt = edges[i][2];

      if (distance[u] != INT_MAX && ((distance[u] + wt) < distance[v]))
      {
        flag = 1;
        distance[v] = distance[u] + wt;
      }
    }
    if (flag == 0)
    {
      return distance[dest ];
    }
  }
  // -ve Cycle Check
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0] ;
    int v = edges[i][1];
    int wt = edges[i][2];

    if (distance[u] != INT_MAX && ((distance[u] + wt) < distance[v]))
    {
      return INT_MAX;
    }
  }
  return distance[dest - 1];
}

int main()
{
  vector<vector<int>> edges;
  edges.push_back({1, 2, 2});
  edges.push_back({2, 3, -1});
  edges.push_back({1, 3, 2});

  int src = 1, dest = 3, v = 3;

  cout << "Min Distance of Dest: ";
  int ans = bellmanFord(edges, src, dest, v);
  cout << ans << endl;
}