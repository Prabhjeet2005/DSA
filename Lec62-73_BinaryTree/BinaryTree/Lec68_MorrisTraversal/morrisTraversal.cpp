#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
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

Node *createTree()
{
    int d;
    cout << "Enter Root: ";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << "Enter Left of " << front->data << ": ";
        int l;
        cin >> l;
        if (l != -1)
        {
            front->left = new Node(l);
            q.push(front->left);
        }
        cout << "Enter right of " << front->data << ": ";
        int r;
        cin >> r;
        if (r != -1)
        {
            front->right = new Node(r);
            q.push(front->right);
        }
    }
    return root;
}

void printTree(Node *root)
{
    cout << endl
         << "Tree:-" << endl;
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
    cout << endl;
}

void morrisTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *predecessor = curr->left;
            while(predecessor->right!=NULL && predecessor->right!=curr){
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
// 1 2 3 4 5 -1 6 -1 7 -1 -1 -1 -1 -1 -1
int main()
{
    Node *root = NULL;
    root = createTree();
    printTree(root);
    cout << endl;
    cout << "Morris Traversal:- \n";
    morrisTraversal(root);
}