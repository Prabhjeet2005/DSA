#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, int d)
{
    Node *new_node = new Node(d);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(Node *&head,Node* &tail,Node* &a)
{
    Node *curr=head;
    Node* prev=a;
    Node *fwd;
    Node *temptail = head;

    while(curr!=tail->next){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    tail = temptail;
    head = prev;
}

void revk(Node *&head, int k)
{
    Node *a = NULL;
    Node *temp = head;
    int cnt = 1;
    Node *tail;
    while (temp != NULL)
    {
        a = temp;
        temp = temp->next;
        if(cnt%k==0){
            tail = temp;
            reverse(head,tail,a);

        }
        cnt++;
    }
}

int main()
{
    Node *head = NULL;
    int size, d;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        insertAtEnd(head, d);
    }
    cout << "Before: ";
    print(head);
    revk(head, 2);
    cout << "After: ";
    print(head);
}