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

void sorting(Node *&head)
{
    Node *temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        if (temp->data == 1)
            cnt1++;
        if (temp->data == 2)
            cnt2++;
        temp = temp->next;
    }
    cout << cnt0 << " " << cnt1 << " " << cnt2 << endl;
    temp = head;
    while (temp != NULL)
    {
        if (cnt0 != 0)
        {

            temp->data = 0;
            cnt0--;

        }
        else if (cnt1 != 0)
        {

            temp->data = 1;
            cnt1--;

        }
        else if (cnt2 != 0)
        {

            temp->data = 2;
            cnt2--;
        }
            temp = temp->next;
    }
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
    sorting(head);
    print(head);
}