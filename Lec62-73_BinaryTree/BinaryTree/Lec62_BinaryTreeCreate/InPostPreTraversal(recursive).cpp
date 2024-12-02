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

    cout << "Enter Left of " << data << endl;
    root->left = binaryTree(root->left);

    cout << "Enter Right of " << data << endl;
    root->right = binaryTree(root->right);

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // SLR
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // 1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
    Node *root = NULL;
    root = binaryTree(root);
    cout << "\nPREORDER: ";
    preorder(root);
    cout << "\nINORDER: ";
    inorder(root);
    cout << endl;
    cout << "POSTORDER: ";
    postorder(root);
    cout << endl;
}