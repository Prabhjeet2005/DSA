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

void solve(Node *root, int sum, int &maxSum, int length, int &maxLength)
{
    if (root == NULL)
    {
        if (length > maxLength)
        {
            maxSum = sum;
            maxLength = length;
        }
        if (length == maxLength)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, length + 1, maxLength);
    solve(root->right, sum, maxSum, length + 1, maxLength);
}

int SumLongestPath(Node *root)
{
    int maxSum = 0, sum = 0, length = 0, maxLength = 0;
    solve(root, sum, maxSum, length, maxLength);
    return maxSum;
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << endl;
    printLevelOrder(root);
    cout << "Max Sum: " << SumLongestPath(root) << endl;
}