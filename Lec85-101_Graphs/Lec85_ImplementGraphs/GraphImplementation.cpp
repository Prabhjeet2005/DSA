#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class graph
{
public:
  unordered_map<int, list<int>> adj;

  //  direction true->Directed Graph
  //  direction false->Undirected Graph
  void addEdge(int u, int v, bool direction)
  {
    adj[u].push_back(v);

    if (direction == false)
    {
      adj[v].push_back(u);
    }
  }
  void printAdjList()
  {
    for (auto i : adj)
    {
      cout << i.first << " -> ";
      for (auto j : i.second)
      {
        cout << j << ",";
      }
      cout << endl;
    }
  }
};

int main()
{
  graph g;
  int n, m;
  cout << "Enter No. of Nodes";
  cin >> n;
  cout << "Enter No. of Edges: ";
  cin >> m;
  for (int i = 0; i<m; i++){
    int u, v;
    cout << "Enter u and v: ";
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }
  cout << "Adjacency List:- \n";
  g.printAdjList();
}