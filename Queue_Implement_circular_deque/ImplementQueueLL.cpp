#include <iostream>
#include <queue>
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
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

class Queue
{
public:
    Node *node;
    Node *head;
    Node *tail;
    int qfront;
    int rear;
    Queue(int data)
    {
        Node *node = new Node(data);
        head = node;
        tail = node;
        qfront = 0;
        rear = 1;
    }
    void push(int d)
    {
        Node *newnode = new Node(d);
        tail->next = newnode;
        tail = tail->next;
        rear++;
    }
    int pop()
    {
        if (qfront == rear)
        {
            return -1;
        }
        Node *temp = head;
        if (head->next != NULL)
        {
            head = head->next;
        }
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return temp->data;
    }
    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        return head->data;
    }
    bool isEmpty()
    {
        if (qfront == rear)
        {
            return 1;
        }
        return 0;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int a = 10;
    Queue q(a);
    q.push(20);
    q.push(30);
    q.push(40);
    q.print();
    cout << q.pop() << endl;
    q.print();
    cout << q.front() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.isEmpty() << endl;
}