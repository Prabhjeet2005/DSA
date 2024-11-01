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
void rev(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fow = NULL;

    if (head == NULL || head->next == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        fow = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fow;
    }
    head = prev;
}

void insert(Node *&head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->next = NULL;
    temp->next = node;
}
// Function to add two numbers represented by linked list.
Node *addTwoLists(Node *num1, Node *num2)

{
    rev(num1);
    rev(num2);

    Node *n1 = num1;
    Node *n2 = num2;

    Node *ans = new Node(-1);

    int carry = 0;
    while (n1 != NULL && n2 != NULL)
    {
        int tempsum = n1->data + n2->data + carry;
        carry = tempsum / 10;
        if (tempsum > 9)
        {
            tempsum = tempsum % 10;
            insert(ans, tempsum);
        }
        else
        {
            insert(ans, tempsum);
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    while (n1 != NULL)
    {
        int tempsum = n1->data + carry;
        carry = tempsum / 10;
        if (tempsum > 9)
        {
            tempsum = tempsum % 10;
            insert(ans, tempsum);
        }
        else
        {
            insert(ans, tempsum);
        }
        n1 = n1->next;
    }
    while (n2 != NULL)
    {
        int tempsum = n2->data + carry;

        carry = tempsum / 10;
        if (tempsum > 9)
        {
            tempsum = tempsum % 10;
            insert(ans, tempsum);
        }
        else
        {
            insert(ans, tempsum);
        }
        n2 = n2->next;
    }
    while (carry > 0)
    {
        insert(ans, carry);
        carry = carry / 10;
    }
    ans = ans->next;
    rev(ans);
    while (ans->data == 0)
    {
        ans = ans->next;
    }
    return ans;
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

int main()
{
    Node *arr1 = new Node(3);
    insert(arr1,4);
    insert(arr1, 5);

    Node *arr2 = new Node(4);
    insert(arr2, 5);
    print(arr1);
    print(arr2);

    cout << endl;
    Node *ans = addTwoLists(arr1, arr2);
    print(ans);
    
}