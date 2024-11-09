#include <iostream>
using namespace std;

class TwoStack
{
    int *arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack()
    {
        arr = new int[200];
        size = 200;
        top1 = -1;
        top2 = -1;
    }

    void push1(int x)
    {
        if (top1 == -1)
        {
            top1 = 0;
            arr[top1] = x;
        }
        else if (top2 - top1 == 1 || top1 == size - 1)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else
        {
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x)
    {
        if (top2 == -1)
        {
            top2 = size - 1;
            arr[top2] = x;
        }
        else if (top2 - top1 == 1 || top2 == 0)
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        int ans = 0;
        if (top1 == -1)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        else
        {
            ans = arr[top1];
            top1--;
        }
        return ans;
    }
    int pop2()
    {
        int ans = 0;
        if (top2 == size)
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }
        else
        {
            ans = arr[top2];
            top2++;
        }
        return ans;
    }
};

int main()
{
    TwoStack t;
    t.push1(1);
    t.push2(2);
    cout << t.pop1() << endl;
    t.push1(3);
    cout << t.pop1() << endl;
    cout << t.pop1() << endl;
}