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

vector<Node *> zigZag(Node *root)
{
    queue<Node *> q;
    vector<Node *> result;
    q.push(root);
    bool leftToRight = true;    //THIS IS IMPORTANT

    while (!q.empty())
    {

        int size = q.size();
        vector<Node *> ans(size);

        int index = 0;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (leftToRight)
            {
                index = i;
            }
            else
            {
                index = size - i - 1;
            }

            ans[index] = temp;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight;

        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    // 1 2 3 4 5 6 7 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1

    // USE LEVEL ORDER
    Node *root = NULL;
    createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    zigZag(root);
    vector<Node*>ans=zigZag(root);
    for(auto i:ans){
        cout << i->data << " ";
    }
    cout << endl;
}