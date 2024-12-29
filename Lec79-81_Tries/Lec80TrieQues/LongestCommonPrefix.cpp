#include <iostream>
#include <vector>
using namespace std;

/*
QUESTION :-
You are given an array ‘ARR’ consisting of ‘N’ strings.
Your task is to find the longest common prefix among all these strings.
If there is no common prefix, you have to return an empty string.

A prefix of a string can be defined as a substring obtained after
removing some or all characters from the end of the string.

For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it
is present as a prefix in all strings. Hence, the answer is “cod”.
*/

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;
  int cntChild;

  TrieNode(char ch)
  {
    data = ch;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
    cntChild = 0;
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
      root->cntChild++;
    }
    insertUtil(child, word.substr(1));
  }

  void insertTrie(string word)
  {
    insertUtil(root, word);
  }

  void getLCP(string str, string &ans)
  {
    for (int i = 0; i < str.length(); i++)
    {
      if (root->cntChild == 1)
      {
        ans.push_back(str[i]);
        int index = str[i] - 'a';
        root = root->children[index];
      }
      else
      {
        return;
      }
    }
  }
};

int main()
{
  vector<string> arr = {"coding", "codezon", "coding ninja", "coders"};
  Trie *t = new Trie('\0');

  for (int i = 0; i < arr.size(); i++)
  {
    t->insertTrie(arr[i]);
  }

  string ans = "";
  string first = arr[0];

  t->getLCP(first, ans);
  cout << ans << endl;
}

// string getLongestCommonPrefix(vector<string> arr)
// {
//   int n = arr.size();
//   string ans = "";

//   for (int i = 0; i < arr[0].size(); i++)
//   {
//     bool isMatch = true;
//     char ch = arr[0][i];

//     for (int j = 1; j < arr.size(); j++)
//     {

//       if (i < arr[j].size() && ch != arr[j][i])
//       {
//         isMatch = false;
//         break;
//       }
//     }
//     if (isMatch == false)
//     {
//       break;
//     }
//     ans.push_back(ch);
//   }
//   return ans;
// }