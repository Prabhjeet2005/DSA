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

Node *solve(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    else if (root->data > d)
    {
        root->left = solve(root->left, d);
    }
    else
    {
        root->right = solve(root->right, d);
    }
    return root;
}

Node *insertBST(Node *&root)
{
    cout << "Enter Data: ";
    int d;
    cin >> d;

    while (d != -1)
    {
        root = solve(root, d);
        cin >> d;
    }
    return root;
}

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

Node *createTree(Node *&root)
{
    cout << "Enter ROOT: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << "Enter left of: " << temp->data;
            int ldata;
            cin >> ldata;
            if (ldata != -1)
            {
                temp->left = new Node(ldata);
                q.push(temp->left);
            }

            cout << "Enter right of: " << temp->data << endl;
            int rdata;
            cin >> rdata;
            if (rdata != -1)
            {
                temp->right = new Node(rdata);
                q.push(temp->right);
            }
        }
    }
    return root;
}

bool checkBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = checkBST(root->left, min, root->data);
        bool right = checkBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

bool validateBST(Node *root)
{
    return checkBST(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    cout << endl;
    printLevelOrder(root);
    if (validateBST(root))
    {
        cout << "IT IS BST\n";
    }
    else
    {
        cout << "It IS NOT BST \n";
    }
}