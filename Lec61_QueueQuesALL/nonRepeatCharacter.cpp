// Input  : s = "aabc"
// Output :     "a#bb"

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

string nonrepeat(string &s)
{
    queue<int> q;
    unordered_map<char, int> count;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front()); // just insert the frontmost element if NON REPEATING
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string s = "aabc";
    string ans = nonrepeat(s);
    cout << ans << endl;
}