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
    cout << "Enter root: ";
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

        cout << "Enter Left of " << temp->data << endl;
        int ldata;
        cin >> ldata;
        if (ldata != -1)
        {
            temp->left = new Node(ldata);
            q.push(temp->left);
        }

        cout << "Enter Right of " << temp->data << endl;
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            temp->right = new Node(rdata);
            q.push(temp->right);
        }
    }
}

void levelOrderPrint(Node *root)
{
    if (root->data == -1)
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

int Balance(Node *root, bool &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = Balance(root->left, ans);
    int right = Balance(root->right, ans);
    int height = max(left, right) + 1;

    ans = abs(left - right) <= 1;

    return height;
}

bool checkBalance(Node *root)
{
    bool ans = 1;
    int a = Balance(root, ans);
    return ans;
}

vector<int> zigZag(Node *root)
{
    vector<int> result;
    queue<Node *> q;
    if (root == NULL)
    {
        return result;
    }
    q.push(root);
    bool ltor = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        int index = 0;

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            if (ltor)
            {
                index = i;
            }
            else
            {
                index = size - i - 1;
            }

            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        ltor = !ltor;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> BoundaryTraverse(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    traverseLeft(root, ans);
    traverseLeaf(root, ans);
    traverseRight(root->right, ans);

    return ans;
}

vector<int> verticalTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        int hd = temp.second.first;
        int lvl = temp.second.second;
        Node *frontNode = temp.first;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    createTree(root);
    levelOrderPrint(root);
    // checkBalance(root) == 1 ? cout << "Balanced" << endl : cout << "Not Balanced\n";
    vector<int> ans = verticalTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}