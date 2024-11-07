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

void insertAtEnd(Node *&head, int data)
{
    Node *new_node = new Node(data);
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

Node *revk(Node *head, int k)
{
    // base Case
    if (head == NULL)
    {
        return NULL;
    }
    // if k< length then don't reverse
    int size = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    if (size < k)
    {
        return head;
    }
    // Reverse LL
    Node *curr = head;
    Node *fwd = NULL;
    Node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count++;
    }

    //
    if (curr != NULL)
    {
        head->next = revk(curr, k);
    }

    return prev;
}

int main()
{
    int size;
    cin >> size;
    Node *head = NULL;
    for (int i = 0; i < size; i++)
    {
        int d;
        cin >> d;
        insertAtEnd(head, d);
    }
    int k;
    cin >> k;
    print(head);
    cout << "After: ";
    head = revk(head, k);
    print(head);
    cout << endl;
}
