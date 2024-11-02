#include <iostream>
using namespace std;
class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        // Write your code here.
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack,
    // and false otherwise.
    bool enqueue(int value)
    {
        // Write your code here.
        if ((front == 0 && rear == size - 1) ||
            (rear == (front - 1) % (size - 1)))
        {
            return 0;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
        return 1;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (front == -1)
        {
            return -1;
        }
        else if (front == rear)
        {
            int f = arr[front];
            front = rear = -1;
            return f;
        }
        else if (front == size - 1)
        {
            int f = arr[front];
            arr[front] = -1;
            front = 0;
            return f;
        }
        else
        {
            int f = arr[front];
            arr[front] = -1;
            front++;
            return f;
        }
    }
};

int main()
{
    CircularQueue q(5);
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(10) << endl;
    cout << q.enqueue(10) << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}