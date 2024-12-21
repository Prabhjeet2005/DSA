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

void calcInorder(Node* root, vector<int>&inorder){
  if(root == NULL){
    return;
  }
  calcInorder(root->left, inorder);
  inorder.push_back(root->data);
  calcInorder(root->right, inorder);
}

void flattenBst(Node *&root)
{
  if (root == NULL)
  {
    return;
  }
  vector<int> inorder;
  calcInorder(root, inorder);

  Node *initial = new Node(inorder[0]);
  Node *curr = initial;

  for (int i = 1; i < inorder.size(); i++)
  {
    Node *temp = new Node(inorder[i]);
    curr->right = temp;
    temp->left = NULL;
    curr = curr->right;
  }
  curr->right = NULL;
}

int main()
{
  // 10 6 12 2 8 11 15 -1
  Node *root = NULL;
  createTree(root);
  cout << endl;
  printLevelOrder(root);
  cout << endl;
  flattenBst(root);
  printLevelOrder(root);
  cout << endl;
}
