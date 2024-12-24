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

void createTree(Node *&root)
{
  cout << "Enter root: ";
  int d;
  cin >> d;
  root = new Node(d);
  if (d == -1)
  {
    return;
  }
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();

    cout << "Enter Left of " << front->data << " : ";
    int ldata;
    cin >> ldata;
    if (ldata != -1)
    {
      front->left = new Node(ldata);
      q.push(front->left);
    }

    cout << "Enter Right of " << front->data << " : ";
    int rdata;
    cin >> rdata;
    if (rdata != -1)
    {
      front->right = new Node(rdata);
      q.push(front->right);
    }
  }
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

int countNode(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int ans = 1 + countNode(root->left) + countNode(root->right);
  return ans;
}

bool isCompleteBinaryTree(Node *root, int index, int n)
{
  if (root == NULL)
  {
    return true;
  }
  if (index >= n)
  {
    return false;
  }

  bool left = isCompleteBinaryTree(root->left, 2 * index + 1, n);
  bool right = isCompleteBinaryTree(root->right, 2 * index + 2, n);
  return (left && right);
}

bool isMaxHeap(Node *root)
{
  // Now it is a CBT so No need to check if root->left == NULL
  if (root->left == NULL && root->right == NULL)
  {
    return true;
  }
  if (root->right == NULL)
  {
    return root->data > root->left->data;
  }
  bool left = isMaxHeap(root->left);
  bool right = isMaxHeap(root->right);
  return (left && right && (root->data > root->left->data && root->data > root->right->data));
}

bool isBinaryTreeHeap(Node *root)
{
  int index = 0;
  if (isCompleteBinaryTree(root, index, countNode(root)) && isMaxHeap(root))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Node *root = NULL;
  createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  cout << "IsBinaryTreeHeap : " << isBinaryTreeHeap(root) << endl;
}