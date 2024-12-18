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

Node *solve(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    else if (root->data > d)
    {
        root->left = solve(root->left, d);
    }
    else
    {
        root->right = solve(root->right, d);
    }
    return root;
}

Node *insertBST(Node *&root)
{
    cout << "Enter Data: ";
    int d;
    cin >> d;

    while (d != -1)
    {
        root = solve(root, d);
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
}

int successor(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

Node *delBST(Node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return root->right;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            int mini = successor(root->right);
            root->data = mini;
            root->right = delBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = delBST(root->left, val);
    }
    else
    {
        root->right = delBST(root->right, val);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insertBST(root);
    cout << endl;
    printLevelOrder(root);
    cout << endl
         << "Enter No. To Delete: ";
    int val;
    cin >> val;
    root = delBST(root, val);
    printLevelOrder(root);
}