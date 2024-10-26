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
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insert(Node *&head, int d)
{
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // newnode->next = temp->next;
    temp->next = newnode;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *middle(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        cout << "Fast: " << fast->data << " Slow: " << slow->data << endl;
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *&left, Node *&right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            ans->next = left;
            ans = ans->next;
            left = left->next;
        }
        else
        {
            ans->next = right;
            ans = ans->next;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        ans->next = left;
        ans = ans->next;
        left = left->next;
    }
    while (right != NULL)
    {
        ans->next = right;
        ans = ans->next;
        right = right->next;
    }
    return temp->next;
}

Node *mergeSort(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = middle(head);


    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main()
{
    Node *head = new Node(4);
    insert(head, 5);
    insert(head, 9);
    insert(head, 2);
    insert(head, 4);
    insert(head, 4);
    head = mergeSort(head);
    print(head);
}