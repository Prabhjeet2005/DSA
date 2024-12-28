#include <iostream>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
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

  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
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

  bool searchUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      return root->isTerminal;
    }
    int index = word[0] - 'A';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }
    return searchUtil(child, word.substr(1));
  }

  void searchTrie(string word)
  {
    cout << "Present OR Not: " << searchUtil(root, word) << endl;
  }

  void removeUtil(TrieNode* &root, string word){
    if(word.length() == 0){
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'A';
    TrieNode* child;
    if(root->children[index] != NULL){
      child = root->children[index];
    }
    else{
      return;
    }
    removeUtil(child, word.substr(1));
  }

  void removeTrie(string word){
    removeUtil(root, word);
    cout << "Removed" << endl;
  }
};

int main()
{
  Trie *t = new Trie();

  t->insertTrie("PRABHJEET");
  t->searchTrie("PRABHJEET");
  cout << "After Removal:-\n";
  t->removeTrie("PRABHJEET");
  t->searchTrie("PRABHJEET");
}