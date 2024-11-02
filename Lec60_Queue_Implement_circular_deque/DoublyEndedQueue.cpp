#include <iostream>
using namespace std;
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
    // the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if (front != 0 && rear == (front - 1) % (size - 1) ||
            front == 0 && rear == size - 1)
        {
            return 0;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = x;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }

        return 1;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into
    // the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if (front != 0 && rear == (front - 1) % (size - 1) ||
            (rear == size - 1 && front == 0))
        {
            return false;
        }
        else if (rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }

        return 1;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is
    // empty, otherwise returns the popped element.
    int popFront()
    {
        int popped = 0;
        // Write your code here.
        if (front == -1)
        {
            return -1;
        }
        else if (front == rear)
        {
            popped = arr[front];
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            popped = arr[front];
            arr[front] = -1;
            front = 0;
        }
        else
        {
            popped = arr[front];
            arr[front] = -1;
            front++;
        }
        return popped;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is
    // empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        int pop = 0;
        if (rear == -1)
        {
            return -1;
        }
        else if (rear == front)
        {
            pop = arr[rear];
            arr[rear] = -1;
            rear = front = -1;
        }
        else if (rear == 0 && front != 0)
        {
            pop = arr[rear];
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            pop = arr[rear];
            arr[rear] = -1;
            rear--;
        }
        return pop;
    }

    // Returns the first element of the deque. If the deque is empty, it returns
    // -1.
    int getFront()
    {
        // Write your code here.
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns
    // -1.
    int getRear()
    {
        // Write your code here.
        if (rear == -1)
        {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if (rear == -1)
        {
            return 1;
        }
        return 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if (front != 0 && rear == (front - 1) % (size - 1) ||
            (front == 0 && rear == size - 1))
        {
            return true;
        }
        return false;
    }
};