#include <iostream>
#include <queue>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump *p, int n)
{
    int balance = 0, lack = 0, pump = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            lack += balance;
            balance = 0;
            pump = i + 1;
        }
    }
    return (lack + balance >= 0) ? pump : -1;
}
/*
Input:
Enter N: 4
4 6 6 5 7 3 4 5
*/

int main()
{
    petrolPump *p;

    int petrol, n, distance;
    cout << "Enter N: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> petrol >> distance;
        p[i].petrol = petrol;
        p[i].distance = distance;
    }
    int ans = tour(p, n);
    cout << ans << endl;
}