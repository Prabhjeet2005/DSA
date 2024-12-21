#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void printLevelOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
      Node *front = q.front();
      q.pop();

      if (front == NULL)
      {
        cout << endl;
        if (!q.empty())
        {
          q.push(NULL);
        }
      }
      else
      {
        cout << front->data << " ";
        if (front->left)
        {
          q.push(front->left);
        }
        if (front->right)
        {
          q.push(front->right);
        }
      }
    }
  }
}

Node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
  if (i >= preorder.size())
  {
    return NULL;
  }
  if (preorder[i] <= mini || preorder[i] >= maxi)
  {
    return NULL;
  }
  Node *root = new Node(preorder[i++]);
  root->left = solve(preorder, mini, root->data, i);
  root->right = solve(preorder, root->data, maxi, i);
  return root;
}

Node *createBST(vector<int> &preorder)
{
  int mini = INT_MIN;
  int maxi = INT_MAX;
  int i = 0;
  Node *root = NULL;
  root = solve(preorder, mini, maxi, i);
  return root;
}

int main()
{
  vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
  Node *root = NULL;

  root = createBST(preorder);

  printLevelOrder(root);
  cout << endl;
}