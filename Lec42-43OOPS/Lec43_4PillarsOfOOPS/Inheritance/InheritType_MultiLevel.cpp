#include<iostream>
using namespace std;

class A{
    public:
        int age = 10;
};

class B: public A{

};

class C : public B
{
};

int main(){
    C c1;
    cout << c1.age << endl;
}