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

void lcaBST(Node *root)
{
  int n1, n2;
  cout << "Enter node1 && Node2: ";
  cin >> n1 >> n2;

  Node *temp = root;

  while (temp != NULL)
  {
    if (temp->data < n1 && temp->data < n2)
    {
      temp = temp->right;
    }
    else if (temp->data > n1 && temp->data > n2)
    {
      temp = temp->left;
    }
    else
    {
      break;
    }
  }
  cout << "Lca is: " << temp->data << endl;
}

int main()
{
  // 50 25 75 10 30 80 -1
  Node *root = NULL;
  root = createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  lcaBST(root);
}