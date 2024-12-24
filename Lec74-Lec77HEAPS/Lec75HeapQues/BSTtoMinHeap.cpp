#include <iostream>
#include <vector>
#include <queue>
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

void createTree(Node *&root)
{
  cout << "Enter Root: ";
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

    cout << "Enter Left of: " << front->data << " : ";
    int ld;
    cin >> ld;
    if (ld != -1)
    {
      front->left = new Node(ld);
      q.push(front->left);
    }

    cout << "Enter Right of: " << front->data << " : ";
    cin >> ld;
    if (ld != -1)
    {
      front->right = new Node(ld);
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

void calcInorder(Node *root, vector<int> &inorder)
{
  if (root == NULL)
  {
    return;
  }
  calcInorder(root->left, inorder);
  inorder.push_back(root->data);
  calcInorder(root->right, inorder);
}

void changeToMinHeap(Node *&root, vector<int> inorder, int &index)
{
  if (root == NULL)
  {
    return;
  }
  root->data = inorder[index++];
  changeToMinHeap(root->left, inorder, index);
  changeToMinHeap(root->right, inorder, index);
}

void BSTToMinHeap(Node *&root)
{
  vector<int> inorder;
  calcInorder(root, inorder);
  int index = 0;
  changeToMinHeap(root, inorder, index);
}

int main()
{
  Node *root = NULL;
  createTree(root);
  cout << endl;
  printLevelOrder(root);

  BSTToMinHeap(root);
  cout << "MinHeap:- \n";
  printLevelOrder(root);
}
