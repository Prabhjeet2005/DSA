#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
    void printTree(Node* root){
        if(root==NULL){
            return;
        }
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }

    Node* solve(vector<int>postorder, vector<int>inorder, int &postIndex,int inorderStart,
    int inorderEnd,unordered_map<int,int>findIndex){
        if(postIndex == -1 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[postIndex--];
        Node* root = new Node(element);
        int pos = findIndex[element];

        root->right = solve(postorder, inorder, postIndex, pos+1, inorderEnd, findIndex);
        root->left = solve(postorder,inorder, postIndex,inorderStart,pos-1,findIndex);
        return root;
    }

    public:
    void InPost(vector<int>postorder, vector<int>inorder){
        unordered_map<int, int> findIndex;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            findIndex[inorder[i]] = i;
        }
        int postIndex = n - 1;
        Node *ans = solve(postorder, inorder, postIndex, 0, n-1, findIndex);
        printTree(ans);
    }
};

int main()
{
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};

    Solution ob;
    ob.InPost(postorder,inorder);
    cout << endl;
}