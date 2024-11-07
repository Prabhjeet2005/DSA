#include <iostream>
#include <queue>
using namespace std;

class kQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot, n, size;

public:
    kQueue(int k, int size)
    {
        n = k;
        this->size = size;
        arr = new int[size];

        next = new int[size];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }
        freespot = 0;
    }

    void enqueue(int qn, int x)
    {
        if (freespot == -1)
        {
            cout << "OverFlow" << endl;
            return;
        }

        int index = freespot;
        freespot = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;

        rear[qn - 1] = index;

        arr[index] = x;
    }

    int dequeue(int qn)
    {
        int index = front[qn - 1];
        if (index == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        // Move the front pointer to the next element
        front[qn - 1] = next[index];

        // Put the current index back to the free list
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{
    kQueue q(3, 6);
    q.enqueue(1, 10);
    q.enqueue(1, 20);
    q.enqueue(1, 30);
    q.enqueue(1, 40);
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
}