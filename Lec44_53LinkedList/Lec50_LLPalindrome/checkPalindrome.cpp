#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

void insertAtEnd(Node *&head, int data)
{
    Node *node = new Node(data);
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

void rev(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    head = prev;
}

Node *mid(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast != NULL)
        slow = slow->next;

    return slow;
}

bool isPalindrome(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    int len = 0;
    Node *temp = head;
    Node *middle = mid(head);
    rev(middle);
    cout << endl;
    Node *f = head;
    Node *s = middle;
    while (s != NULL)
    {
        if (s->data == f->data)
        {
            s = s->next;
            f = f->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    Node *head = new Node(1);
    insertAtEnd(head, 2);
    // insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    // insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    print(head);
    cout << isPalindrome(head);
    Node *temp = mid(head);
}