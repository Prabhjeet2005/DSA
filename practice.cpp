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
    void printTree(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        printTree(root->left);
        printTree(root->right);
        cout << root->data << " ";
    }

public:
    Node *solve(vector<int> preorder, vector<int> inorder, int &preIndex, int inorderStart,
                int inorderEnd, unordered_map<int, int> &findIndex, int size)
    {
        if (preIndex == size || inorderStart > inorderEnd)
        {
            return NULL;
        }
        int element = preorder[preIndex++];
        Node *root = new Node(element);
        int posInorder = findIndex[element];

        root->left = solve(preorder, inorder, preIndex, inorderStart, posInorder - 1, findIndex, size);
        root->right = solve(preorder, inorder, preIndex, posInorder + 1, inorderEnd, findIndex, size);

        return root;
    }

    void preInToPost(vector<int> preorder, vector<int> inorder)
    {
        unordered_map<int, int> findIndex;
        int size = inorder.size();
        for (int i = 0; i < size; i++)
        {
            findIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        Node *ans = solve(preorder, inorder, preIndex, 0, size - 1, findIndex, size);
        printTree(ans);
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