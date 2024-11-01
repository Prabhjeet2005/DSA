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
    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
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

Node *sortTwoLists(Node *first, Node *second)
{
    // Write your code here.
    int c1 = 0, c2 = 0;
    Node *f = first;
    Node *s = second;
    if (f == NULL)
        return second;
    if (s == NULL)
        return first;

    Node *newList = new Node(-1);
    Node *temp = newList;
    Node *node = newList;

    while (f != NULL && s != NULL)
    {
        if (f->data <= s->data)
        {
            node->next = f;
            node = node->next;
            f = f->next;
        }
        else
        {
            node->next = s;
            node = node->next;
            s = s->next;
        }
    }
    while (f != NULL)
    {
        node->next = f;
        node = node->next;
        f = f->next;
    }
    while (s != NULL)
    {
        node->next = s;
        node = node->next;
        s = s->next;
    }
    delete node;
    return temp->next;
}

int main()
{
    Node *first = new Node(1);
    insert(first, 3);
    insert(first, 4);
    insert(first, 5);
    insert(first, 6);

    Node *second = new Node(0);
    insert(second, 2);
    insert(second, 4);
    insert(second, 5);
    insert(second, 7);

    Node* ans = sortTwoLists(first,second);
    print(ans);
}