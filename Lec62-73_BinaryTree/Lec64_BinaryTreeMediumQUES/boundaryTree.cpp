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
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node *root)
{
    cout << "Enter root: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left of: " << temp->data << endl;
        int left;
        cin >> left;
        if (left != -1)
        {
            temp->left = new Node(left);
            q.push(temp->left);
        }
        cout << "Enter right of: " << temp->data << endl;
        int right;
        cin >> right;
        if (right != -1)
        {
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> treeBoundary(Node *root)
{
   
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left, ans);

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    traverseRight(root->right, ans);

    return ans;
}

int main()
{
        // 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

        // 1 2 3 8 9 4 5 -1 -1 -1 -1 -1 6 -1 -1 -1 7 -1 -1
        Node *root = NULL;
    root = createTree(root);
    levelOrder(root);
    vector<int> ans = treeBoundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}