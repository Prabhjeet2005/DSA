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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for LEFT: " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for RIGHT: " << data << endl;
    root->right = buildTree(root->right);

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

int main()
{
    Node *root = NULL;
    // 1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
    root = buildTree(root);
    cout << endl;
    levelOrderTraversal(root);
}