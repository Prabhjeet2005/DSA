#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
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

class Stack
{
    Node *arr;
    Node *next;
    Node *head;
    Node *tail;
    int top;

public:
    Stack()
    {
        arr = NULL;
        head = arr;
        tail = arr;
        top = -1;
    }

    void push(int d)
    {
        if (top == -1)
        {
            arr = new Node(d);
            head = arr;
            tail = arr;
        }
        else
        {
            Node *newnode = new Node(d);
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        top++;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        top--;
        Node *temp = head;
        Node *popped = tail;
        while (temp->next != tail && temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
        return popped->data;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        return tail->data;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
}