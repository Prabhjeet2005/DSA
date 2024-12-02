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

void buildLevel(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter Root: ";
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

        cout << "Enter Left of: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter Right of: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void printLevel(Node *root)
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

int main()
{
    Node *root = NULL;
    buildLevel(root);
    printLevel(root);
}