#include <iostream>
#include <queue>
#include <vector>
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

class compare
{
public:
  bool operator()(Node *a, Node *b)
  {
    return a->data > b->data;
  }
};

void insertEnd(Node *&head, int d)
{
  if (head == NULL)
  {
    head = new Node(d);
    head->next = NULL;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new Node(d);
}

void display(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *mergeKSortedLL(vector<Node *> listArray, int k)
{
  priority_queue<Node *, vector<Node *>, compare> minHeap;
  for (int i = 0; i < k; i++)
  {
    if (listArray[i] != NULL)
    {
      minHeap.push(listArray[i]);
    }
  }

  Node* head = NULL;
  Node* tail = NULL;

  while(!minHeap.empty()){
    Node *top = minHeap.top();
    minHeap.pop();
    if(top->next != NULL){
      minHeap.push(top->next);
    }

    if(head == NULL){
      head = top;
      tail = top;
    }
    else
    {
      tail->next = top;
      tail = top;
    }
  }
  return head;
}

int main()
{
  Node *head1 = NULL;
  insertEnd(head1, 4);
  insertEnd(head1, 6);
  insertEnd(head1, 8);

  Node *head2 = NULL;
  insertEnd(head2, 2);
  insertEnd(head2, 5);
  insertEnd(head2, 7);

  Node *head3 = NULL;
  insertEnd(head3, 1);
  insertEnd(head3, 9);

  cout << "LL1: ";
  display(head1);
  cout << "LL2: ";
  display(head2);
  cout << "LL3: ";
  display(head3);

  vector<Node *> listArray = {head1, head2, head3};
  int k = 3;
  Node *ans = mergeKSortedLL(listArray, k);

  cout << "Final Sorted & Merged LL: ";
  display(ans);
}
