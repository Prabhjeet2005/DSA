#include <iostream>
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

    cout << "Enter Left of: " << root->data << endl;
    root->left = binaryTree(root->left);
    cout << "Enter Right of: " << root->data << endl;
    root->right = binaryTree(root->right);

    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int main()
{
    Node *root = NULL;
    root = binaryTree(root);
    cout << endl;
    cout << "height: " << height(root) << endl;
}