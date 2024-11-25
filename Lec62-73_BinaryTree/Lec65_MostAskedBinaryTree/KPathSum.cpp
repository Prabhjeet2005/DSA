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

class Solution
{
private:
    void solve(Node *root, int &count, int k, vector<int> path)
    {
        if (root == NULL)
        {
            return;
        }
        path.push_back(root->data);
        int size = path.size();

        solve(root->left, count, k, path);
        solve(root->right, count, k, path);

        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (k == sum)
            {
                count++;
            }
        }
    }

public:
    int KPathSum(Node *root, int k)
    {
        int count = 0;
        vector<int> path;

        solve(root, count, k, path);

        return count;
    }
};

int main()
{

    cout << "Enter Test Cases: ";
    int tc;
    cin >> tc;
    while (tc != 0)
    {
        Node *root = NULL;
        createTree(root);
        printLevelOrder(root);

        cout << "Enter k: ";
        int k;
        cin >> k;

        Solution ob;
        int ans = ob.KPathSum(root, k);
        cout << "No. of Paths: " << ans << endl;
        tc--;
    }
}
