#include <iostream>
#include <vector>
#include <map>
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

void createTree(Node *&root)
{
    int data;
    cout << "Enter root: ";
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        cout << "Enter Left of " << frontNode->data << endl;
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            frontNode->left = new Node(ldata);
            q.push(frontNode->left);
        }

        cout << "Enter Right of: " << frontNode->data << endl;
        int rdata;
        cin >> rdata;

        if (rdata != -1)
        {
            frontNode->right = new Node(rdata);
            q.push(frontNode->right);
        }
    }
}

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

Node* LCA(Node* root,int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }
    if(left!= NULL && right == NULL){
        return left;
    }
    if(right !=NULL && left == NULL){
        return right;
    }else{
        return NULL;
    }
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << endl;
    printLevelOrder(root);
    cout << "\n\nEnter N1 & N2: ";
    int n1, n2;
    cin >> n1 >> n2;
    Node *ans = LCA(root, n1, n2);
    if (ans == NULL)
    {
        cout << "Not Found\n";
    }
    else
    {
        cout << "LCA: " << ans->data << endl;
    }
}