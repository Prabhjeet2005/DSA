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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftTree = height(root->left);
    int rightTree = height(root->right);

    int ans = max(leftTree, rightTree) + 1;

    return ans;
}

int main()
{
    // 1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
    Node *root = NULL;
    root = binaryTree(root);
    cout << endl;
    cout << "height: " << height(root) << endl;
    cout << endl;
}