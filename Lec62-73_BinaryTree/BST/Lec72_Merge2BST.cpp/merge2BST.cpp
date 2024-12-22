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
    Node *temp = new Node(d);
    return temp;
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

Node *createTree(Node *root)
{
  cout << "Enter root: ";
  int d;
  cin >> d;
  while (d != -1)
  {
    root = createBST(root, d);
    cin >> d;
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

// BST to DOUBLY LL
void convertBstToDLL(Node *root, Node *&head)
{
  if (root == NULL)
  {
    return;
  }
  convertBstToDLL(root->right, head);

  root->right = head;
  if (head != NULL)
  {
    head->left = root;
  }
  head = root;

  convertBstToDLL(root->left, head);
}

int displayCount(Node *root)
{
  Node *temp = root;
  int cnt = 0;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    cnt++;
    temp = temp->right;
  }
  cout << endl;
  return cnt;
}

Node *mergeDLL(Node *head1, Node *head2)
{
  Node *ans = new Node(-1);
  Node *temp = ans;

  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data < head2->data)
    {
      ans->right = head1;
      head1->left = ans;
      ans = ans->right;
      head1 = head1->right;
    }
    else
    {
      ans->right = head2;
      head2->left = ans;
      ans = ans->right;
      head2 = head2->right;
    }
  }

  while (head1 != NULL)
  {
    ans->right = head1;
    head1->left = ans;
    ans = ans->right;
    head1 = head1->right;
  }
  while (head2 != NULL)
  {
    ans->right = head2;
    head2->left = ans;
    ans = ans->right;
    head2 = head2->right;
  }
  temp = temp->right;
  temp->left = NULL;
  return temp;
}

Node *DLLToBst(Node *&head, int n)
{
  if (head == NULL || n == 0)
  {
    return NULL;
  }

  Node *left = DLLToBst(head, n / 2);

  Node *root = head;
  root->left = left;
  head = head->right;

  root->right = DLLToBst(head, n - n / 2 - 1);
  return root;
}

int main()
{
  // 2 1 3 -1 4 -1
  Node *root1 = NULL;
  root1 = createTree(root1);
  printLevelOrder(root1);

  Node *head1 = NULL;
  convertBstToDLL(root1, head1);
  cout << "DLL1: ";
  int n1 = displayCount(head1);

  Node *root2 = NULL;
  root2 = createTree(root2);
  printLevelOrder(root2);

  Node *head2 = NULL;
  convertBstToDLL(root2, head2);
  cout << "DLL2: ";
  int n2 = displayCount(head2);

  Node *merged = mergeDLL(head1, head2);
  merged->left = NULL;

  cout << "Merged DLL: ";
  int n3 = displayCount(merged);
  Node *ans = DLLToBst(merged, n3);
  cout << "Ans:\n ";
  printLevelOrder(ans);
}