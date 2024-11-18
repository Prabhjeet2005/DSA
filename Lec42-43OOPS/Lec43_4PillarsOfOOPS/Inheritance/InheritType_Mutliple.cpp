#include <iostream>
using namespace std;

class A
{
public:
    int age = 10;
};
class B
{
public:
    int weight = 50;
};
class C : public A, public B
{
};
int main()
{
    C c1;
    cout << c1.age << " " << c1.weight << endl;
}