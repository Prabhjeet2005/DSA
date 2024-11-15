#include <iostream>
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

void createTree(Node *&root)
{
    cout << "Enter Root: ";
    int data;
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
        Node *temp = q.front();
        q.pop();

        cout << "Enter Left of: " << temp->data << endl;
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            temp->left = new Node(ldata);
            q.push(temp->left);
        }

        cout << "Enter Right of: " << temp->data << endl;
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            temp->right = new Node(rdata);
            q.push(temp->right);
        }
    }
}

void Inorder(Node *r1, Node *r2, bool &ans)
{
    if (r1 == NULL || r2 == NULL)
    {
        return;
    }
    Inorder(r1->left, r2->left, ans);

    //COMPARE DATA
    
    if (r1->data != r2->data)
    {
        ans = 0;
    }
    Inorder(r1->right, r2->right, ans);
}

bool identical(Node *r1, Node *r2)
{
    bool ans = 1;
    Inorder(r1, r2, ans);
    return ans;
}

void levelOrder(Node *root)
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

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    cout << "TREE1:-\n";
    createTree(root1);
    levelOrder(root1);
    cout << "TREE2:-\n";
    createTree(root2);
    levelOrder(root2);
    bool ans = identical(root1, root2);
    cout << ans << endl;
    ans == 1 ? cout << "Identical\n" : cout << "Not IDENTICAL\n";
}