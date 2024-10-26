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

void insert(Node *&head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
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

Node* sorting(Node *&head)
{
    Node *temp = head;

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (temp->data == 2)
        {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }

    head = zeroHead->next;
    if (oneHead->next != NULL)
    {

        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    twoTail->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(0);
    insert(head, 2);
    insert(head, 2);
    insert(head, 0);
    insert(head, 1);
    insert(head, 1);
    insert(head, 0);

    print(head);
    head=sorting(head);
    print(head);
}