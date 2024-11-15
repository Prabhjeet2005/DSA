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

pair<int, int> diameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int height = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(left.first, max(right.first, height));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
void dans(pair<int, int> ans)
{
    cout << "Diameter: " << ans.first << endl;
}

int main()
{
    // 10 20 40 -1 -1 60 -1 -1 30 -1 -1
    Node *root = NULL;
    root = createTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    pair<int, int> ans = diameter(root);
    dans(ans);
}