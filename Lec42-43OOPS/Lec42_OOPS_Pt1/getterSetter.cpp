#include <iostream>
using namespace std;
class Hero
{
    int health;
    char level;

public:
    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }
    void setLevel(char l)
    {
        level = l;
    }
};
int main()
{
    Hero h1;
    h1.setHealth(10);
    h1.setLevel('A');
    cout << h1.getHealth() << endl
         << h1.getLevel() << endl;
}