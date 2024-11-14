#include <iostream>
#include <utility>
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
    cout << "Enter Data: ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter Left of: " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter Right of: " << data << endl;
    root->right = createTree(root->right);

    return root;
}
// first Diameter, second Height
pair<int, int> diameterFast(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int height = left.second + 1 + right.second;

    int op1 = left.first;
    int op2 = right.first;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, height));
    // ans.second=max(left.second,right.second)+1;

    return ans;
}

int diameter(Node *root)
{
    return diameterFast(root).first;
}

int main()
{
    // 1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
    Node *root = NULL;
    root = createTree(root);
    cout << diameter(root);
}