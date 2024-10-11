#include <iostream>
using namespace std;
void rev(string &str, int i)
{

    if (i > str.length() / 2)
    {
        return;
    }
    swap(str[i], str[str.length() - i - 1]);
    rev(str, i - 1);
}
int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;
    rev(str, 0);
    cout << str << endl;
}