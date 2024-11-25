#include <iostream>
using namespace std;

int main()
{

    int target = 37;
    int i = 1;
    int cnt = 4;
    for (int i = 1; i <= 37; i += 2)
    {
        cnt++;
        if (cnt == 9)
        {
            cnt = 5;
        }
    }
    cout << "ANS: " << cnt << endl;
}