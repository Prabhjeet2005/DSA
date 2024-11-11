#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this->data=data;
        this->right=NULL;
        this->left = NULL;
    }
};

Node* binaryTree(Node* root){
    cout<<"Enter Data: ";
    int data;
    cin>>data;

    root=new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter to left to "<<data<<endl;
    root->left=binaryTree(root->left);

    cout << "Enter to right to " << data << endl;
    root->right = binaryTree(root->right);

    return root;
}

void preorder(Node* root){
    
}

int main(){
    Node* root=NULL;
    root = binaryTree(root);
    // 1 2 -1 -1 3 -1 -1
    levelOrderTraversal(root);
}



/*
1 3 4 -1 -1 9 -1 -1 7 10 -1 -1 -1
INORDER: (LSR) 6 3 5 2 4 1
POSTORDER(LRS) 6 5 3 4 2 1
PREORDER(SLR) 1 2 3 6 5 4

*/