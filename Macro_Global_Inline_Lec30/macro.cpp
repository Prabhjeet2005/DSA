#include <iostream>
using namespace std;
#define Pattern(height, width)          \
    for (int i = 0; i < height; i++)    \
    {                                   \
        for (int j = 0; j < width; j++) \
        {                               \
            cout << "*";                \
        }                               \
        cout << endl;                   \
    }

int main()
{
    Pattern(4, 3);
    return 0;
}