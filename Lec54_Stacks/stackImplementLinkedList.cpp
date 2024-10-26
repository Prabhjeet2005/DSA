#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
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
public:
    int top;
    Node *node;
    Node *head;
    Node *tail;
    Stack(int data)
    {
        node = new Node(data);
        head = node;
        tail = node;
        top = -1;
    }
    void push(int element)
    {
        top++;
        Node *newnode = new Node(element);
        newnode->next = tail->next;
        tail->next = newnode;
        tail = tail->next;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            top--;
            Node *temp = head;
            while (temp->next != tail && temp != tail)
            {
                temp = temp->next;
            }
            Node *inst = tail;
            tail = temp;
            tail->next = NULL;
            delete inst;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "UnderFLow" << endl;
        }
        else
        {
            cout << "Top: " << tail->data << endl;
        }
    }
    bool empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack st(10);
    st.push(20);
    st.push(30);
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.pop();
    st.peek();
    cout << st.empty() << endl;
}