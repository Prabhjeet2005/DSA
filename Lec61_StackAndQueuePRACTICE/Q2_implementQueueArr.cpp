#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        int ans = 0;
        if (front == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        else if (front == rear)
        {
            ans = arr[front];
            arr[front] = -1;
            front = rear = -1;
        }
        else
        {
            ans = arr[front];
            arr[front] = -1;
            front++;
        }
        return ans;
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(6);
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
    cout << q.peek() << endl;
    cout << q.dequeue() << endl;
}