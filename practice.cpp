#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        this->next = NULL;
    }
};

void createLL(Node *&head)
{
    int d;
    cout << "Enter head: ";
    cin >> d;
    if (d == -1)
    {
        return;
    }
    else
    {
        head = new Node(d);
        head->next = NULL;
    }
}

void insertEnd(Node *&head, int d)
{

    if (d == -1)
    {
        return;
    }
    else
    {
        Node *newnode = new Node(d);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *calcMid(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *ans = new Node(-1);
    Node *curr = ans;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ans->next = head1;
            head1 = head1->next;
            ans = ans->next;
        }
        else
        {
            ans->next = head2;
            head2 = head2->next;
            ans = ans->next;
        }
    }

    while (head1 != NULL)
    {
        ans->next = head1;
        ans = ans->next;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        ans->next = head2;
        ans = ans->next;
        head2 = head2->next;
    }
    return curr->next;
}

Node *mergeSort(Node *&head1)
{
    if (head1 == NULL || head1->next == NULL)
    {
        return head1;
    }
    Node *mid = calcMid(head1);

    Node *left = head1;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main()
{
    // 7 3 4 8 3 1 9 10 -1
    Node *head1 = NULL;
    createLL(head1);
    int data;
    cout << "Enter Data: ";
    cin >> data;
    while (data != -1)
    {
        insertEnd(head1, data);
        cin >> data;
    }
    cout << endl
         << "Linked List1: ";
    display(head1);

    Node *mergedList = mergeSort(head1);
    cout << "Sorted List: ";
    display(mergedList);
}