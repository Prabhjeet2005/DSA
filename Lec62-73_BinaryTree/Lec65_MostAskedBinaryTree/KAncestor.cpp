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
    Node *solve(Node *root, int k, int &count, int target, int &ans)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == target)
        {
            return root;
        }

        Node *leftAns = solve(root->left, k, count, target, ans);
        Node *rightAns = solve(root->right, k, count, target, ans);

        if ((leftAns != NULL || rightAns != NULL))
        {
            count++;
            if (count == k)
            {
                ans = root->data;
            }
            return root;
        }
        else
        {
            return NULL;
        }
    }

public:
    int kAncestor(Node *root, int k, int node)
    {
        int count = 0;
        int ans = -1;
        solve(root, k, count, node, ans);
        return ans;
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

        cout << "Enter Node to Find Ancestor: ";
        int d;
        cin >> d;
        Node *node = new Node(d);

        Solution ob;
        int ans = ob.kAncestor(root, k, node->data);
        cout << "Ans: " << ans << endl;

        tc--;
    }
}
