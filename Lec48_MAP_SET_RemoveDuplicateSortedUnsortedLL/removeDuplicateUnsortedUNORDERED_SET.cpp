#include <iostream>
#include <unordered_set>
using namespace std;

// 5 1 2 2 2 2

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            delete prev;
            this->next = NULL;
            this->prev = NULL;
        }
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
        node->prev = temp;
        temp->next = node;
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

void removeDup(Node *&head)
{
    unordered_set<int> visited;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (visited.find(temp->data) != visited.end())
        {
            Node *t = temp;
            prev->next = temp->next;
            temp = temp->next;
            t->next = NULL;
            delete t;
        }
        else if (visited.find(temp->data) == visited.end())
        {
            prev = temp;
            visited.insert(temp->data);
            temp = temp->next;
        }
    }
}


//count()->unordered_set

/*
void removeDup(Node *&head)
{
    unordered_set<int> visited;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (visited.count(temp->data) > 0)
        {
            Node *t = temp;
            prev->next = temp->next;
            temp = temp->next;
            t->next = NULL;
            delete t;
        }
        else
        {
            prev = temp;
            visited.insert(temp->data);
            temp = temp->next;
        }
    }
}
*/

int main()
{
    Node *head = NULL;
    int size, d;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> d;
        insertAtEnd(head, d);
    }
    cout << endl;
    print(head);
    removeDup(head);
    print(head);
}