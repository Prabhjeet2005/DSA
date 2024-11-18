#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> verticalTraversal(Node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> nodes;

    queue<pair<Node *, pair<int, int>>> q;

    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;

        int hd = temp.second.first;   // Horizontal Distance
        int lvl = temp.second.second; // LEVEL

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1

    // USE LEVEL ORDER
    Node *root = NULL;
    createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    vector<int> ans = verticalTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}