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

int length(Node *&head)
{
    Node *temp = head;
    int cnt = 1;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void printMiddle(Node *head, int starting)
{
    Node *temp = head;
    int cnt = 1;
    while (cnt < starting)
    {
        temp = temp->next;
        cnt++;
    }
    print(temp);
}

int main()
{
    Node *head = NULL;
    int size;
    cin >> size;
    int d;
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        insertAtEnd(head, d);
    }
    int len = length(head);
    len = (len / 2) + 1;
    print(head);
    printMiddle(head, len);
}