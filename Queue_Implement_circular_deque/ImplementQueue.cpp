#include <iostream>
#include <queue>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue()
    {
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "QUEUE FULL" << endl;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return 1;
        }
        return 0;
    }

    int front()
    {
        if (qfront == rear)
        {
            cout << "QUEUE EMPTY" << endl;
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    cout << q.isEmpty() << endl;
    cout << q.dequeue() << endl;
}