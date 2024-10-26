#include <iostream>
#include <map>
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
    Node *node = new Node(d);
    if (head == NULL)
    {
        head = node;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void firstLoopNode(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    // Write your code here.
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
}

int main()
{
    Node *head = NULL;

    for (int i = 1; i <= 50; i += 10)
    {

        insertAtEnd(head, i + 9);
    }
    // print(head);
    Node *t = head->next;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    firstLoopNode(head);
    print(head);
}