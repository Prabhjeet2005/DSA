#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class graph
{
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction)
  {
    adj[u].push_back(v);
    if (direction == false)
    {
      adj[v].push_back(u);
    }
  }

  void printAdj(){
    for(auto i:adj){
      cout << i.first << " -> ";
      for(auto j:i.second){
        cout << j << " , ";
      }
      cout << endl;
    }
  }
};

int
main()
{
  int n = 5,m =5;
  graph g;
  for (int i = 0; i < m; i++)
  {
    cout << "u & v: ";
    int u,v;
    cin >> u >> v;
    g.addEdge(u, v, 1);
  }
  g.printAdj();
}