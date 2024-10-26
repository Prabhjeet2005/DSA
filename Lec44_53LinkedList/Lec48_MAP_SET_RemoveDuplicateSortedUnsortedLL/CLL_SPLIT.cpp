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
        new_node->next = head;
        return;
    }

    else
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int count(Node *&head)
{
    Node *temp = head;
    temp = temp->next;
    int cnt = 1;
    while (temp != head)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void split(Node *&head)
{
    int len = count(head);
    int l = len / 2 ;
    Node *curr = head;
    Node *prev;
    int count = 1;

    while (count < l)
    {
        count++;
        prev = curr;
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = head;
    Node *a = temp;
    while ( temp->next!=head)
    {
        temp = temp->next;

    }
    temp->next = a;
    print(head);
    print(a);
}

int main()
{
    int size, d;
    cin >> size;
    Node *head = NULL;
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        insertAtEnd(head, d);
    }

    cout << endl;
    split(head);
}