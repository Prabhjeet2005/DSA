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

Node *createBST(Node *root, int d)
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
  else
  {
    root->right = createBST(root->right, d);
  }
  return root;
}

void createTree(Node *&root)
{
  cout << "Enter Data: ";
  int d;
  cin >> d;
  while (d != -1)
  {
    root = createBST(root, d);
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

void calcInorder(Node *root, vector<int> &in)
{
  if (root == NULL)
  {
    return;
  }
  Node *curr = root;
  while (curr != NULL)
  {
    if (curr->left == NULL)
    {
      in.push_back(curr->data);
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
        pred->right = NULL;
        in.push_back(curr->data);
        curr = curr->right;
      }
    }
  }
}

void twoSum(Node *root)
{
  cout << "Enter Target: ";
  int target;
  cin >> target;

  vector<int> inorder;

  calcInorder(root, inorder);

  bool ans = false;

  int i = 0, j = inorder.size() - 1;
  while (i != j)
  {
    int sum = inorder[i] + inorder[j];
    if (sum == target)
    {
      ans = true;
      break;
    }
    else if (sum > target)
    {
      j--;
    }
    else
    {
      i++;
    }
  }

  if (ans)
  {
    cout << "Two Sum EXISTS" << endl;
  }
  else
  {
    cout << "Two Sum Not Exists" << endl;
  }
}

int main()
{
  // 10 6 12 2 8 11 15 -1
  Node *root = NULL;
  createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  twoSum(root);
}
