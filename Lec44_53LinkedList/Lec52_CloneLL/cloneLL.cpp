#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

Node *copyList(Node *head)
{

    Node *newList = new Node(-1);
    Node *newHead = newList;
    Node *temp = head;

    while (temp != NULL)
    {

        newList->next = temp;
        newList->next->random = temp->random;
        newList->next->data = temp->data;
        temp = temp->next;
    }
    newList = newHead;
    newHead = newList->next;
    newList = NULL;
    delete newList;
    return newHead;
}