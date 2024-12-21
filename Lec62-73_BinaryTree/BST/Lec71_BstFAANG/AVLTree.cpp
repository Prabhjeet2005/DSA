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

Node *BST(Node *root, int d)
{
  if (root == NULL)
  {
    return root = new Node(d);
  }
  else if (root->data > d)
  {
    root->left = BST(root->left, d);
  }
  else if (root->data < d)
  {
    root->right = BST(root->right, d);
  }
  return root;
}

void createBST(Node *&root)
{
  cout << "Enter root: ";
  int d;
  cin >> d;
  while (d != -1)
  {
    root = BST(root, d);
    cin >> d;
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

vector<int> MorrisTraversalInorder(Node *root)
{
  vector<int> ans;
  if (root == NULL)
  {
    return ans;
  }
  Node *curr = root;
  while (curr != NULL)
  {
    if (curr->left == NULL)
    {
      ans.push_back(curr->data);
      curr = curr->right;
    }
    else
    {
      Node *pred = curr->left;
      while (pred && pred->right != NULL && pred->right != curr)
      {
        pred = pred->right;
      }
      if (pred->right == NULL)
      {
        pred->right = curr;
        curr = curr->left;
      }
      else
      {
        ans.push_back(curr->data);
        curr = curr->right;
        pred->right = NULL;
      }
    }
  }
  return ans;
}

Node *BalancedBST(int s, int e, vector<int> &inorder)
{
  if (s > e)
  {
    return NULL;
  }
  int mid = s + (e - s) / 2;
  Node *root = new Node(inorder[mid]);
  root->left = BalancedBST(s, mid - 1, inorder);
  root->right = BalancedBST(mid + 1, e, inorder);

  return root;
}

int main()
{

  // 10 8 4 2 12 16 20 -1

  Node *root = NULL;
  createBST(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  cout << "Inorder: ";
  vector<int> inorder = MorrisTraversalInorder(root);
  cout << endl;
  Node *balancedTree = BalancedBST(0, inorder.size() - 1, inorder);
  cout << endl;
  printLevelOrder(balancedTree);
  cout << endl;
}