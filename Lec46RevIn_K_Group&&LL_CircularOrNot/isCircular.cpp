/*bool isCircular(Node *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return true;
    }
    // if (head->next == NULL)
    // {
    //     return false;
    // }
    Node *temp = head->next;
    Node *track;

    while (temp != NULL && temp->data != head->data)
    {
        track = temp;
        temp = temp->next;
        track->next = NULL;
    }
    return temp == head;
}*/