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
    queue<Node *> q;
    cout << "Enter Root: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();
        cout << "Enter Left Of: " << temp->data << endl;
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            Node *t = new Node(ldata);
            temp->left = t;
            q.push(t);
        }

        cout << "Enter Right OF: " << temp->data << endl;
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            Node *t = new Node(rdata);
            temp->right = t;
            q.push(t);
        }
    }
}

void levelOrder(Node *root)
{
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

int Sum(Node *root, bool &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int left = Sum(root->left, ans);
    int right = Sum(root->right, ans);

    ans = root->data == left + right;
    return root->data + left + right;
}

bool isSumTree(Node *root)
{
    bool ans = 1;
    int s = Sum(root, ans);
    return ans;
}
/*
pair<bool, int> Sum(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = Sum(root->left);
    pair<bool, int> right = Sum(root->right);

    bool condition = root->data == left.second + right.second;
    pair<bool, int> ans;
    if (left.first && right.first && condition)
    {
        ans.first = true;
        ans.second = root->data + left.second + right.second;
    }
    else
    {
        ans.first = false;
        ans.second = root->data + left.second + right.second;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    return Sum(root).first;
}
*/


int main()
{
    // 10 20 40 -1 -1 60 -1 -1 -1

    // USE LEVEL ORDER
    Node *root = NULL;
    createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    isSumTree(root) == 1 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
}