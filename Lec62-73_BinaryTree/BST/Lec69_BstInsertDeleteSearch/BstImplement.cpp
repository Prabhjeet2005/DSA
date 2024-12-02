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

Node* root

void insertBST(Node *root)
{
    int d;
    cout << "Enter root: ";
    cin >> d;
    while (d != -1)
    {
        root = createTree(root, d);
        cin >> d;
    }
}

int main()
{
    Node *root = NULL;
    insertBST(root);
}