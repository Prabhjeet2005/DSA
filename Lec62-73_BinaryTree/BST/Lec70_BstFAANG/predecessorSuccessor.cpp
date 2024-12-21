#include <iostream>
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

Node *createBST(Node *&root, int d)
{
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }
  else if (root->data > d)
  {
    root->left = createBST(root->left, d);
  }
  else if (root->data < d)
  {
    root->right = createBST(root->right, d);
  }
  return root;
}

Node *createTree(Node *&root)
{
  cout << "Enter Data: ";
  int data;
  cin >> data;

  while (data != -1)
  {
    root = createBST(root, data);
    cin >> data;
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

void solvePredSucc(Node *root, int &predAns, int &succAns, int k)
{
  if (root == NULL)
  {
    return;
  }
  if (root->data == k)
  {
    if (root->left)
    {
      Node* temp = root->left;
      while (temp->right != NULL)
      {
        temp = temp->right;
      }
      predAns = temp->data;
    }
    if (root->right)
    {
      Node* temp = root->right;
      while (temp->left != NULL)
      {
        temp = temp->left;
      }
      succAns = temp->data;
    }
    return;
  }
  else if (root->data > k)
  {
    succAns = root->data;
    solvePredSucc(root->left, predAns, succAns, k);
  }
  else
  {
    predAns = root->data;
    solvePredSucc(root->right, predAns, succAns, k);
  }
}

pair<int, int> predecessorSuccessor(Node *root)
{
  int k;
  cout << "Eneter K: ";
  cin >> k;
  pair<int, int> output;
  if (root == NULL)
  {
    return make_pair(-1, -1);
  }
  int predAns = -1;
  int succAns = -1;

  solvePredSucc(root, predAns, succAns, k);
  output.first = predAns;
  output.second = succAns;
  return output;
}

void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main()
{
  // 15 10 20 8 12 16 25 -1
  Node *root = NULL;
  root = createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  inorder(root);
  cout << endl;
  pair<int, int> ans = predecessorSuccessor(root);
  cout << "Pred: " << ans.first << " , Succ: " << ans.second << endl;
  cout << endl;
}