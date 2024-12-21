#include <iostream>
using namespace std;

class Base
{
    int b = 20;

public:
    Base()
    {
        this->b = 50;
    }
    friend class Derived;
};

class Derived
{
public:
    void display()
    {
        Base objBase;
        cout << "Base class b = " << objBase.b << endl;
    }
};

int main()
{
    Derived d;
    d.display();
}
