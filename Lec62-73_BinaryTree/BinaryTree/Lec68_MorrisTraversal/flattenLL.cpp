#include<iostream>
#include<queue>

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

void createTree(Node* &root){
    int data;
    cout << "Enter Root: ";
    cin >> data;
    root = new Node(data);
    if(data == -1){
        return;
    }
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *front = q.front();
        q.pop();

        cout << "Enter Left Of " << front->data << " : ";
        int ldata;
        cin >> ldata;
        if(ldata!=-1){
            front->left = new Node(ldata);
            q.push(front->left);
        }
        cout << "Enter right Of " << front->data << " : ";
        int rdata;
        cin >> rdata;
        if (rdata != -1)
        {
            front->right = new Node(rdata);
            q.push(front->right);
        }
    }
}

void printTree(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

void flattenTree(Node* &root){
    Node *curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while(pred->right != NULL && pred->right != curr->right){
                pred = pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr->right;
                curr->right = curr->left;
            }
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

int main(){
    Node* root = NULL; 
    createTree(root);
    cout << endl;
    printTree(root);
    cout<<endl;
    flattenTree(root);
}