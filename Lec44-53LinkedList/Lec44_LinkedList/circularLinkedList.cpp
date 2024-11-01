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

void insertAtEnd(Node *&tail, int d)
{
    Node *new_node = new Node(d);
    if (tail == NULL)
    {
        tail = new_node;
        tail->next = new_node;
        return;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
}

void print(Node *&tail)
{
    Node *temp = tail;
    if (temp->next == tail)
    {
        cout << temp->data << endl;
    }
    else
    {
        temp = tail->next;
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}

void deleteElement(Node *&tail, int element)
{
    Node *curr = tail->next;
    Node *prev;
    if (tail->next->data == element)
    {
        Node *temp = tail->next;
        tail->next = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    while ((curr->data != element) && (curr != tail))
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == tail)
    {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        tail = prev;
        return;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void insertAtMid(Node *&tail, int d, int position)
{
    Node *new_node = new Node(d);
    if (position == 1)
    {
        new_node->next = tail->next;
        tail->next = new_node;
        return;
    }
    else
    {
        Node *temp = tail->next;
        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp == tail)
        {
            insertAtEnd(tail, d);
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteAtEnd(Node *&tail)
{
    Node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    Node *curr = temp;
    temp = tail;
    curr->next = tail->next;
    tail = curr;
    temp->next = NULL;
    delete temp;
}

void deleteAtMid(Node *&tail, int position)
{
    Node *temp = tail->next;
    if (position == 1)
    {
        Node *curr = temp->next;
        tail->next = curr;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == tail)
        {
            deleteAtEnd(tail);
            return;
        }
        Node *curr = temp; // Delete this
        temp = temp->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void count(Node *&tail)
{
    Node *temp = tail->next;
    int cnt = 1;
    while (temp != tail)
    {
        temp = temp->next;
        cnt++;
    }
    cout << "Length is: " << cnt << endl;
}

int main()
{

    Node *tail = NULL;

    insertAtEnd(tail, 20);
    cout << "tail-> " << tail->data << endl;
    print(tail);

    insertAtEnd(tail, 30);
    cout << "tail-> " << tail->data << endl;
    print(tail);

    insertAtEnd(tail, 40);
    cout << "tail-> " << tail->data << endl;
    print(tail);

    insertAtMid(tail, 99, 1);
    cout << "tail-> " << tail->data << endl;
    print(tail);

    insertAtMid(tail, 95, 5);
    cout << "tail-> " << tail->data << endl;
    print(tail);

    deleteElement(tail, 95);
    cout << "tail-> " << tail->data << endl;
    print(tail);
    count(tail);
}