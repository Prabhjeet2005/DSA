#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool push(int value)
    {
        if ((rear == front - 1 % (size - 1)) || (front == 0 && rear == size - 1))
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

    int pop()
    {
        int f = 0;
        if (front == -1)
        {
            return -1;
        }
        else if (front == 0 && rear == 0)
        {
            f = arr[front];
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            f = arr[front];
            arr[front] = -1;
            front = 0;
        }
        else
        {
            f = arr[front];
            arr[front] = -1;
            front++;
        }
        return arr[front];
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << front << " " << arr[i] << " " << rear << " ,";
        }
        cout << endl;
    }
};

int main() 
{
    Queue q(4);
    cout << q.push(10) << endl;
    cout << q.push(20) << endl;
    cout << q.push(30) << endl;
    cout << q.push(40) << endl;
    cout << q.push(50) << endl;
    q.print();
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
}