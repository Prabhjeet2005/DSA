#include<iostrem>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data,Node* &head){
            this->data = data;
            this->next = head;
        }
};

void insertAtHead(Node* &head,int d){
    Node *newnode = new Node(d);

}

int main(){
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;


}