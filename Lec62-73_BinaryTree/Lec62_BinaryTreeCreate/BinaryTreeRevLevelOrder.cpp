#include <iostream>
#include <queue>
#include <stack>
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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *binaryTree(Node *root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Left to " << data << endl;
    root->left = binaryTree(root->left);

    cout << "Right to " << data << endl;
    root->right = binaryTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    cout << endl;
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

void revLevelOrder(Node *root)
{
    cout << endl
         << endl;

    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        s.push(temp);
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
    cout << "Reverse Order:-" << endl
         << endl;
    while (!s.empty())
    {
        if (s.top() == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << s.top()->data << " ";
        }
        s.pop();
    }
    cout << endl
         << endl;
}

int main()
{
    Node *root = NULL;
    root = binaryTree(root);
    // 1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
    levelOrderTraversal(root);
    revLevelOrder(root);
}