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

// int height(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int left = height(root->left);
//     int right = height(root->right);

//     int ans = max(left, right) + 1;
//     return ans;
// }

pair<bool, int> isBalanced(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(1, 0);
        return p;
    }

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.first = left.first && right.first && diff;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main()
{
    // 10 20 40 -1 -1 60 -1 -1 -1

    // USE LEVEL ORDER
    Node *root = NULL;
    createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    pair<bool, int> ans = isBalanced(root);
    cout << ans.first << endl;
}