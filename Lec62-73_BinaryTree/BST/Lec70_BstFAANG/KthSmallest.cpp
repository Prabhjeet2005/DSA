#include <queue>
#include <iostream>
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

Node *createBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    else if (root->data > d)
    {
        root->left = createBST(root->left, d);
    }
    else
    {
        root->right = createBST(root->right, d);
    }
    return root;
}

Node *createTree(Node *&root)
{
    cout << "Enter root: ";
    int d;
    cin >> d;

    while (d != -1)
    {
        root = createBST(root, d);
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
}

Node *predecessor(Node *root)
{
    Node *temp = root;
    root = root->left;
    while (root->right != NULL && root->right != temp)
    {
        root = root->right;
    }
    return root;
}

void solve(Node *root, int k, int &cnt, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cnt++;
            if (cnt == k)
            {
                ans = curr->data;
                break;
            }
            curr = curr->right;
        }
        else
        {
            Node *pred = predecessor(curr);
            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cnt++;
                if (cnt == k)
                {
                    ans = curr->data;
                    break;
                }
                curr = curr->right;
            }
        }
    }
}

int kthSmallest(Node *root, int k)
{
    int cnt = 0;
    int ans = -1;
    solve(root, k, cnt, ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    cout << endl;
    printLevelOrder(root);
    cout << endl;
    int k;
    cout << "Enter k: ";
    cin >> k;
    int ans = kthSmallest(root, k);
    cout << ans << endl;
}