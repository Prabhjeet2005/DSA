#include <iostream>
using namespace std;

class complex
{
public:
    int re;
    double comp;

public:
    void operator+(complex &obj){
        int val1 = this->re;
        int val2 = obj.re;
        double val3 = this->comp;
        double val4 = obj.comp;
        cout << "Sum of Complex: " << (val1 + val2) << " + " << "j" << val3 + val4 << endl;
    }
};

int main()
{
    complex c1, c2;
    c1.re = 10;
    c2.re = 20;
    c1.comp = 3.5;
    c2.comp = 3;
    c1 + c2;
}