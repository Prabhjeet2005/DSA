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

Node *createTree(Node *root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter Left OF: " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter Right of: " << data << endl;
    root->right = createTree(root->right);

    return root;
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(right,left) + 1;

    return ans;
}

int diameter(Node* root){
    
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;
}