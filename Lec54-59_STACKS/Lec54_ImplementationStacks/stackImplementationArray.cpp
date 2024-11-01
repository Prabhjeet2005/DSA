#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "OverFlow";
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "UnderFlow";
        }
        else
        {
            top--;
        }
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "UnderFlow"<<endl;
        }
        else
        {
            cout << "Top Element: " << arr[top] << endl;
        }
    }
    bool empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.peek();

    st.pop();
    st.peek();

    cout << st.empty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.peek();
}