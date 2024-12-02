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

void createTree(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return;
    }
    else if (root->data > d)
    {
        createTree(root->left, d);
    }
    else
    {
        createTree(root->right, d);
    }
}

void createBST(Node *&root)
{
    int d;
    cout << "Enter root: ";
    cin >> d;
    if (d == -1)
    {
        return;
    }

    while (d != -1)
    {
        createTree(root, d);
        cin >> d;
    }
}

void levelOrderPrint(Node *root)
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
    if (root == NULL)
    {
        return 0;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

Node *delTree(Node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
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
            return temp;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 2 Children
        else
        {
            int mini = successor(root->right);
            root->data = mini;
            root->right = delTree(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = delTree(root->left, val);
    }
    else
    {
        root->right = delTree(root->right, val);
    }
    return root;
}

void deleteionFromBST(Node *&root)
{
    cout << "Enter Val To Delete: ";
    int d;
    cin >> d;
    root = delTree(root, d);
}

int main()
{
    // 50 40 70 80 30 45 -1
    Node *root = NULL;
    createBST(root);
    cout << "\nBefore Deletion\n";
    levelOrderPrint(root);
    deleteionFromBST(root);
    cout << "\nAfter Deletion\n";
    levelOrderPrint(root);
}