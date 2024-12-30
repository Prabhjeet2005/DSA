#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;
  TrieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie
{
public:
  TrieNode *root;
  Trie(char ch)
  {
    root = new TrieNode(ch);
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index])
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insertTrie(string word)
  {
    insertUtil(root, word);
  }

  void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix)
  {
    if (curr->isTerminal) // isTerminal is important
    {
      temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      TrieNode *next = curr->children[ch - 'a'];
      if (next != NULL)
      {
        prefix.push_back(ch);
        printSuggestion(next, temp, prefix);  //All further combo of that particular letter
        prefix.pop_back();
      }
    }
  };

  vector<vector<string>> phoneDirectory(vector<string> arr, string querySearch)
  {

    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < querySearch.length(); i++)
    {
      char lastch = querySearch[i];
      prefix.push_back(lastch);

      TrieNode *curr = prev->children[lastch - 'a'];
      if (curr == NULL)
      {
        break;
      }
      vector<string> temp;
      printSuggestion(curr, temp, prefix);  //All Combination from a letter
      output.push_back(temp);
      temp.clear();
      prev = curr;
    }
    return output;
  }
};

int main()
{
  vector<string> arr = {"cod", "coding", "codding", "code", "coly"};
  string querySearch = "coding";

  Trie *t = new Trie('\0');

  for (int i = 0; i < arr.size(); i++)
  {
    t->insertTrie(arr[i]);
  }

  vector<vector<string>> output = t->phoneDirectory(arr, querySearch);
  for (int i = 0; i < output.size(); i++)
  {
    for (int j = 0; j < output[i].size(); j++)
    {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
