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
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);

        pair<int, int> ans;
        ans.first = root->data + leftAns.second + rightAns.second;
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return ans;
    }

public:
    int NonAdjacent(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main()
{
    // 1 2 3 4 - 1 5 6 - 1 - 1 - 1 - 1 - 1 - 1
    cout << "Enter Test Cases: ";
    int tc;
    cin >> tc;
    while (tc != 0)
    {
        Node *root = NULL;
        createTree(root);
        printLevelOrder(root);

        Solution ob;
        int ans = ob.NonAdjacent(root);
        cout << "Ans: " << ans << endl;

        tc--;
    }
}
