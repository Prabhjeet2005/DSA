#include <iostream>
#include <map>
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
        temp->next = node;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isLoop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    map<Node *, bool> visited;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    // int size, d;
    // cin >> size;


    //JUST FOR EXAMPLE A LOOP I HAVE CREATED


    for (int i = 1; i <= 5; i++)
    {

        insertAtEnd(head, i);
    }
    Node *t = head->next;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    cout << isLoop(head) << endl;

}