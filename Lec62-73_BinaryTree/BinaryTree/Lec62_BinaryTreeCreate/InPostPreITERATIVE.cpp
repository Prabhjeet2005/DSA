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
    queue<Node* >q;
    q.push(root);

    

}

void inorder(Node *root)
{
}

void postorder(Node *root)
{
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