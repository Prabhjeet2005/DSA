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
    data = d;
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

vector<int> MorrisInorder(Node *root)
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
      while (pred->right != NULL && pred->right != curr)
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

vector<int> mergeBST(Node *root1, Node *root2)
{
  // Write your code here.
  vector<int> inorderRoot1 = MorrisInorder(root1);
  vector<int> inorderRoot2 = MorrisInorder(root2);

  int i = 0, j = 0;
  vector<int> ans;

  while (i < inorderRoot1.size() && j < inorderRoot2.size())
  {
    if (inorderRoot1[i] < inorderRoot2[j])
    {
      ans.push_back(inorderRoot1[i]);
      i++;
    }
    else
    {
      ans.push_back(inorderRoot2[j]);
      j++;
    }
  }
  while (i < inorderRoot1.size())
  {
    ans.push_back(inorderRoot1[i]);
    i++;
  }
  while (j < inorderRoot2.size())
  {
    ans.push_back(inorderRoot2[j]);
    j++;
  }

  return ans;
}

int main()
{
  
}