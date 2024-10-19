#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void
    operator+(A &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Difference is: " << val1 - val2 << endl;
    }
};
int main(){
    A a1,a2;
    a1.a=10;
    a2.a = 20;
    a1 + a2;
}