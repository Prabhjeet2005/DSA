#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            delete prev;
            this->next = NULL;
            this->prev = NULL;
        }
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *new_node = new Node(d);
    new_node->next = head;
    new_node->prev = head->prev;
    head->prev = new_node;
    head = new_node;
}

void insertAtEnd(Node *&tail, int d)
{
    Node *new_node = new Node(d);
    new_node->next = tail->next;
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{
    Node *new_node = new Node(d);
    Node *temp = head;
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtEnd(tail, d);
        return;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    new_node->prev = temp;
    temp->next = new_node;
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

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAtEnd(Node *&tail)
{
    Node *temp = tail;
    tail = tail->prev;
    tail->next = temp->next;
    temp->prev = NULL;
    delete temp;
}

void deleteAtMiddle(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        deleteAtHead(head);
        return;
    }
    else
    {
        Node *curr = head;
        Node *previous = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            previous = curr;
            cnt++;
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            deleteAtEnd(tail);
            return;
        }
        previous->next = curr->next;
        curr->next->prev = previous;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtEnd(tail, 15);
    print(head);
    insertAtMiddle(head, tail, 3, 20);
    print(head);

    deleteAtMiddle(head, tail, 4);
    print(head);
}