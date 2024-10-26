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

void insertAtEnd(Node *&head, Node *&tail, int d)
{
    Node *new_node = new Node(d);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    else
    {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
}
void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(Node *&head, Node *&tail)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward;
    if (head == tail)
    {
        return;
    }
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    cout << "Enter How many?then enter elements: \n";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int d;
        cin >> d;
        insertAtEnd(head, tail, d);
    }
    reverse(head, tail);
    print(head, tail);
}