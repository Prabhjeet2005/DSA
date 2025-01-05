#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
#include<limits.h>

using namespace std;

vector<int> dijkstra(vector<vector<int>>&edges, int vertices, int e, int src){
  unordered_map<int, list<pair<int,int>>> adj;
  for (int i = 0; i < e; i++){
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  vector<int> distance(vertices);
  for (int i = 0; i<vertices; i++){
    distance[i] = INT_MAX;
  }

  set<pair<int, int>> set;  // pair->{node,distance}
  distance[src] = 0;
  set.insert({src, 0});

  while(!set.empty()){
    auto top = *(set.begin());

    int nodeDist = top.second;
    int node = top.first;

    set.erase(set.begin());

    for(auto neighbour: adj[node]){

      if(nodeDist + neighbour.second < distance[neighbour.first] ){

        auto it = set.find({neighbour.first, distance[neighbour.first]}); //  Delete Existing Entry from Set
        if(it!=set.end()){
          set.erase(it);
        }

        set.insert({neighbour.first, nodeDist + neighbour.second});
        distance[neighbour.first] = nodeDist + neighbour.second;
      }
    }
  }
  return distance;
}

int main()
{
  vector<vector<int>> edges = {
      {0, 1, 7},
      {0, 2, 1},
      {0, 3, 2},
      {1, 2, 3},
      {1, 3, 5},
      {1, 4, 1},
      {3, 4, 7}};
  int vertices = 5;
  int e = 7;
  int src = 0;

  vector<int> dist = dijkstra(edges, vertices, e,src);

  cout << "Dijkstra Shortest Path: ";
  for(auto i: dist){
    cout << i << " ";
  }
  cout << endl;
}