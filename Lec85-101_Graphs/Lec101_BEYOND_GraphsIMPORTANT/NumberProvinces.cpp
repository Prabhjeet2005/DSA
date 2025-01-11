//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adjLst)
  {
    visited[node] = true;
    for (auto neighbour : adjLst[node])
    {
      if (!visited[neighbour])
      {
        dfs(neighbour, visited, adjLst);
      }
    }
  }

public:
  int numProvinces(vector<vector<int>> adj, int V)
  {
    // code here
    unordered_map<int, list<int>> adjLst;
    for (int i = 0; i < adj.size(); i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        if (adj[i][j] == 1 && i != j)
        {
          adjLst[i].push_back(j);
        }
      }
    }
    vector<bool> visited(V);
    int cnt = 0;
    for (int i = 0; i < adj.size(); i++)
    {
      if (!visited[i])
      {
        dfs(i, visited, adjLst);
        cnt++;
      }
    }
    return cnt;
  }
};
// Input
// 1
// 3 
// 1 0 1 0 1 0 1 0 1

    //{ Driver Code Starts.

    int
    main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int V, x;
    cin >> V;

    vector<vector<int>> adj;

    for (int i = 0; i < V; i++)
    {
      vector<int> temp;
      for (int j = 0; j < V; j++)
      {
        cin >> x;
        temp.push_back(x);
      }
      adj.push_back(temp);
    }

    Solution ob;
    cout << ob.numProvinces(adj, V) << endl;

    cout << "~" << "\n";
  }
  return 0;
}
// } Driver Code Ends