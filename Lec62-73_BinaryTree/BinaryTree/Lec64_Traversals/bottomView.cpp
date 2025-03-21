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

vector<int> topTraverse(Node *root)
{
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    
}

int main()
{
    Node *root = NULL;
    createTree(root);
    levelOrderPrint(root);

    vector<int> ans = topTraverse(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}