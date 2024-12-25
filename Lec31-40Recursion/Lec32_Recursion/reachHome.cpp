#include <iostream>
using namespace std;
// tc=> O(n)
void reachHome(int src, int dest)
{
    if (src == dest)
    {
        cout << "Reached Home ";
        return;
    }
    cout << "Source : " << src << " Destination: " << dest << endl;
    src++;
    reachHome(src, dest);
}

int main()
{
    int src = 1, dest = 10;
    reachHome(src, dest);
    return 0;
}