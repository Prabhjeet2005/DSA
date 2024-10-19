#include <iostream>
using namespace std;

class A
{
public:
    int age = 10;
};
class D
{
public:
    int weight = 55;
};
// Hierarchial
class B : public A
{
};
// Multiple + Hierarchial
class C : public A, public D
{
};

int main()
{
    C c1;
    cout << c1.age << " " << c1.weight << endl;
}