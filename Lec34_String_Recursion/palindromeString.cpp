#include <iostream>
using namespace std;

// TC=>O(n)
bool checkPalindrome(string str, int i, int j)
{
    cout << str << " " << str[i] << " " << str[j] << endl;
    if (i > j)
    {
        return 1;
    }
    if (str[i] != str[j])
    {
        return 0;
    }
    if (str[i] == str[j])
    {
        i++;
        j--;
        return checkPalindrome(str, i, j);
    }
}
int main()
{
    cout << "Enter String: ";
    string str;
    cin >> str;
    int ans = checkPalindrome(str, 0, str.length() - 1);
    if (ans == 0)
    {
        cout << "Not Palindrome" << endl;
    }
    else
    {
        cout << "Palindrome" << endl;
    }
}