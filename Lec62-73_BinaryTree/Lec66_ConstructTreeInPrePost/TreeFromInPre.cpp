#include <iostream>
#include <vector>
#include <unordered_map>
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

class Solution
{
public:
    Node *solve(vector<int> pre, vector<int> in, unordered_map<int, int> findIndexInorder,
                int inOrderStart, int inOrderEnd, int &index, int n)
    {
        if (index == n || inOrderStart > inOrderEnd)
        {
            return NULL;
        }

        int element = pre[index++];
        Node *root = new Node(element);
        int position = findIndexInorder[element];

        root->left = solve(pre, in, findIndexInorder, inOrderStart, position - 1, index, n);
        root->right = solve(pre, in, findIndexInorder, position + 1, inOrderEnd, index, n);

        return root;
    }

    void create(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        create(root->left);
        create(root->right);
        cout << root->data << " ";
    }

    void preInToPost(vector<int> pre, vector<int> in)
    {
        unordered_map<int, int> findIndexInorder;
        for (int i = 0; i < pre.size(); i++)
        {
            findIndexInorder[in[i]] = i;
        }
        int n = pre.size();
        int index = 0;
        Node *ans = solve(pre, in, findIndexInorder, 0, n - 1, index, n);

        create(ans);
        cout << endl;
    }
};

int main()
{
    int tc = 1;
    while (tc != 0)
    {
        Solution ob;
        vector<int> pre = {0, 1, 3, 4, 2, 5};
        vector<int> in = {3, 1, 4, 0, 5, 2};

        ob.preInToPost(pre, in);

        tc--;
    }
}