#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "Base Class FUnction\n";
    }
};
class B : public A
{
public:
    void func()
    {
        cout << "Derived Class FUnction\n";
    }
};
int main()
{
    B b;
    b.A::func();
}
