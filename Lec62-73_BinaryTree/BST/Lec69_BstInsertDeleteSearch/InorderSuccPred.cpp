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

void printLevelOrder(Node *root)
{
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
}

void insertBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
    }
    else if (d > root->data)
    {
        insertBST(root->right, d);
    }
    else
    {
        insertBST(root->left, d);
    }
    return;
}

Node *predecessor(Node *root)
{
    
}
Node *successor(Node *root)
{
    
}

void inorderPred(Node *root)
{
    int x;
    cout << "Enter Inorder whose predecessor and successor to Calc: ";
    cin >> x;
    if (root == NULL)
    {
        return;
    }
    Node *temp = root;
    Node *succ, *pred = NULL;
    while (temp!=NULL)
    {
        if(temp->data == x){
            if(temp->left){
                pred = predecessor(temp->left);
            }
            if(temp->right){
                succ = successor(temp->right);
            }
            break;
        }
        else if(temp->data < x){
            pred = temp;
            temp = temp->right;
        }
        else{
            succ = temp;
            temp = temp->left;
        }
    }
    cout << "Temp: " << temp->data << endl;
    cout << "Predeccessor: " << pred->data << endl;
    cout << "Successsor: " << succ->data << endl;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter Data: ";
    cin >> data;
    while (data != -1)
    {
        insertBST(root, data);
        cin >> data;
    }
}

void inorderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}

int main()
{
    Node *root = NULL;
    takeInput(root);
    printLevelOrder(root);
    cout << "\nInorder: ";
    inorderTraverse(root);
    cout << endl;
    inorderPred(root);
    cout << endl;
}