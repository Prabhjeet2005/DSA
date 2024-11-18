#include <iostream>
using namespace std;

class A
{
public:
    int age = 10;
};
class B : public A
{
};
class C : public A
{
};
int main()
{
    C c1;
    B b1;
    cout << b1.age << " " << c1.age << endl;
}