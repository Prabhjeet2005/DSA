#include <iostream>
using namespace std;

class A{
    public:
        virtual ~A(){};
};
class B:public A{
};

int main()
{
    A a;
    B b;

    B &rb1=b;
    A &ra1=dynamic_cast<A &>(rb1);
    cout<<"UPCAST"<<endl;

    A &ra2=b;
    B &rb2=dynamic_cast<B &>(ra2);
    cout << "downcast" << endl;
}