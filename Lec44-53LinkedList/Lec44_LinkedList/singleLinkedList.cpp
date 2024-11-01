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
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node *&tail, int d)
{
    Node *new_node = new Node(d);
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
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

void insertAtMiddle(Node *&tail, Node *&head, int d, int position)
{
    Node *temp = head;
    Node *new_node = new Node(d);
    int cnt = 1;
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(Node *&tail, Node *&head, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if (prev->next == NULL)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}




int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);

    print(head);

    deleteNode(tail, head, 5);
    print(head);
    cout << head->data << " " << tail->data << endl;
}