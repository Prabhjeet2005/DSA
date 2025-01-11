#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void topoSort(int node, stack<int> &stack, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
  visited[node] = true;

  for (auto neighbour : adj[node])
  {
    if (!visited[neighbour])
    {
      topoSort(neighbour, stack, adj, visited);
    }
  }
  stack.push(node);
}

string alienDictionary(vector<string> &dict, int words, int k)
{
  unordered_map<int, vector<int>> adj;
  for (int j = 0; j < words - 1; j++)
  {
    string s1 = dict[j];
    string s2 = dict[j + 1];
    bool change = false;
    int smallerLen = min(s1.size(), s2.size());
    for (int i = 0; i < smallerLen; i++)
    {
      if (s1[i] != s2[i])
      {
        adj[s1[i] - 'a'].push_back(s2[i] - 'a');
        break;
      }
    }
    if(change==false && s1.length() > s2.size()){
      return "Invalid Dictionary";
    }
  }
  stack<int> stack;
  vector<bool> visited(k, false);
  for (int i = 0; i < k; i++)
  {
    if(!visited[i])
    topoSort(i, stack, adj, visited);
  }

  string ans = "";
  while (!stack.empty())
  {
    ans.push_back(stack.top() + 'a');
    stack.pop();
  }
  return ans;
}

int main()
{
  vector<string> dict;
  dict.push_back("baa");
  dict.push_back("abcd");
  dict.push_back("abca");
  dict.push_back("cab");
  dict.push_back("cad");
  int k = 4;
  int words = 5;

  string ans = alienDictionary(dict, words, k);
  cout << "Answer is: " << ans;
}