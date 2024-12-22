#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *createTree(Node *root)
{
  int d;
  cout << "Enter Root: ";
  cin >> d;
  root = new Node(d);
  if (d == -1)
  {
    return NULL;
  }
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();

    cout << "Enter Left of: " << front->data << " ";
    int ldata;
    cin >> ldata;
    if (ldata != -1)
    {
      front->left = new Node(ldata);
      q.push(front->left);
    }

    cout << "Enter Right of: " << front->data << " ";
    int rdata;
    cin >> rdata;
    if (rdata != -1)
    {
      front->right = new Node(rdata);
      q.push(front->right);
    }
  }
  return root;
}

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

class info
{
public:
  int maxi;
  int mini;
  bool isBST;
  int size;
};

info solve(Node *root, int &maximumSize)
{
  if (root == NULL)
  {
    return {INT_MIN, INT_MAX ,true, 0};
  }
  info left = solve(root->left, maximumSize);
  info right = solve(root->right, maximumSize);

  info currNode;
  currNode.maxi = max(left.maxi, root->data);
  currNode.mini = min(right.mini, root->data);
  currNode.size = left.size + right.size + 1;

  if (left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini))
  {
    currNode.isBST = true;
  }
  else
  {
    currNode.isBST = false;
  }

  if (currNode.isBST)
  {
    maximumSize = max(maximumSize, currNode.size);
  }
  return currNode;
}

int LargestBstSize(Node *root)
{
  info temp;
  int maximumSize = 0;
  temp = solve(root, maximumSize);
  return maximumSize;
}

int main()
{
  // 5 2 4 1 3 -1 -1 -1 -1 -1 -1
  Node *root = NULL;
  root = createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  cout << "Largest BST in Binary Tree: " << LargestBstSize(root) << endl;
}