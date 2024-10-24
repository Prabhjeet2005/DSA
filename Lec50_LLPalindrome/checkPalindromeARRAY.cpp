#include <iostream>
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
};

void insertAtEnd(Node *&head, int data)
{
    Node *node = new Node(data);
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

bool isPalindrome(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    int *arr = new int[cnt];
    temp = head;
    int k = 0;
    while (temp != NULL)
    {
        arr[k++] = temp->data;
        temp = temp->next;
    }
    int i = 0, j = cnt - 1;
    while (i < j)
    {
        if (arr[i] != arr[j])
        {
            delete[] arr;
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    delete[] arr;
    return 1;
}
int main()
{
    Node *head = new Node(1);
    insertAtEnd(head, 2);
    // insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    print(head);
    cout << isPalindrome(head);
}