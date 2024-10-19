#include <iostream>
using namespace std;

class Human
{
public:
    int height = 10;
};
class Male : public Human
{
public:
    int getHeight()
    {
        return this->height;
    }
};
int main()
{
    Male m1;
    cout << m1.height << endl;
    cout << m1.getHeight() << endl;
}