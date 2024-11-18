#include <iostream>
using namespace std;

class hero
{
public:
    static int time;
    int health;
    char *name;
    // hero(char name[])
    // {
    //     cout << "Constructor Called\n";
    //     this->name = name;
    // }
    // hero(hero &temp){
    //     char *ch = new char[strlen(temp.name) + 1];
    //     strcpy(ch, temp.name);
    //     this->name = ch;
    // }
};

int hero::time = 9999;
int main()
{

    cout << hero::time << endl;
}