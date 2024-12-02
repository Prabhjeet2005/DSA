#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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

Node *createTree()
{
    int d;
    cout << "Enter Root: ";
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << "Enter Left of " << front->data << ": ";
        int l;
        cin >> l;
        if (l != -1)
        {
            front->left = new Node(l);
            q.push(front->left);
        }
        cout << "Enter right of " << front->data << ": ";
        int r;
        cin >> r;
        if (r != -1)
        {
            front->right = new Node(r);
            q.push(front->right);
        }
    }
    return root;
}

void printTree(Node *root)
{
    cout << endl
         << "Tree:-" << endl;
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
    cout << endl;
}

class Solution
{
    Node *getParentTarget(Node *root, int target, unordered_map<Node *, Node *> &nodeParent)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        nodeParent[root] = NULL;

        Node *targetNode = NULL;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
            {
                targetNode = front;
            }

            if (front->left)
            {
                nodeParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }

    int burnTree(Node *targetNode, unordered_map<Node *, Node *> &nodeParent)
    {
        if (targetNode == NULL)
        {
            return 0;
        }

        int time = 0;
        unordered_map<Node *, bool> visited;

        visited[targetNode] = true;
        queue<Node *> q;
        q.push(targetNode);

        while (!q.empty())
        {
            int size = q.size();
            bool flag = 0;

            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = 1;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = 1;
                }
                if (nodeParent[front] && !visited[nodeParent[front]])
                {
                    q.push(nodeParent[front]);
                    visited[nodeParent[front]] = true;
                    flag = 1;
                }
            }
            if (flag)
            {
                time++;
            }
        }
        return time;
    }

public:
    //
    int minTime(Node *root)
    {
        int target = 5;
        unordered_map<Node *, Node *> nodeParent;
        Node *targetNode = getParentTarget(root, target, nodeParent);

        int ans = burnTree(targetNode, nodeParent);
        return ans;
    }
};

int main()
{
    int tc = 1;
    Node *root = NULL;
    root = createTree();
    printTree(root);
    while (tc != 0)
    {
        Solution ob;
        cout << "Min Time: " << ob.minTime(root) << endl;

        tc--;
    }
}