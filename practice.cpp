#include <iostream>
using namespace std;

struct Example4
{
    char c1;   // 1 byte
    double d1; // 8 bytes
    char c2;   // 1 byte
    int i1;    // 4 bytes
    char c3;   // 1 byte
};

int main()
{
    cout << "Size of Example4: " << sizeof(Example4) << " bytes" << endl;
    return 0;
}
