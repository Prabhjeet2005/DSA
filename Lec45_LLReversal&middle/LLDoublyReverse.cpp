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
        new_node->prev = temp;
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

void reverse(Node *&head)
{
    Node *previous = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = previous;
        previous = curr;
        curr = forward;
    }
    head = previous;
}

int main()
{
    Node *head = NULL;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int d;
        cin >> d;
        insertAtEnd(head, d);
    }
    cout << "Before: ";
    print(head);
    reverse(head);
    cout << "After: ";
    print(head);
}