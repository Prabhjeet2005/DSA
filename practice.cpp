#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

Node *revk(Node *&head, int k)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *f = NULL;

    int cnt = 0;
    Node *temp = head;
    while (curr != NULL && cnt < k)
    {
        f = curr->next;
        curr->next = prev;
        prev = curr;
        curr = f;
        cnt++;
    }

    if (f != NULL && cnt>=k)
    {
        head->next = revk(f, k);
    }
    return prev;
    
}

void print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    int k = 3;
    print(head);
    head = revk(head, k);
    print(head);
}