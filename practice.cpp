#include <iostream>
using namespace std;

void rev(string &str)
{
    int s = 0, e = str.length() - 1;
    while (s < e)
    {
        char temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s++;
        e--;
    }
}

int main()
{

    string str = "Babbar";
    rev(str);
    cout << str << endl;
}