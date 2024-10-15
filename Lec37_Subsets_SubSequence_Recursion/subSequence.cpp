#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(string output, string &str, int index, vector<string> &ans)
{

    if (index >= str.size())
    {
        if (output.size() > 0)
        {
            ans.push_back(output);
        }

        return;
    }

    solve(output, str, index + 1, ans);

    output.push_back(str[index]);
    solve(output, str, index + 1, ans);
}

vector<string> subsequences(string str)
{

    // Write your code here
    vector<string> ans;
    int index = 0;
    string output;
    solve(output, str, index, ans);
    return ans;
}
int main()
{
    vector<string> a = subsequences("abc");
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
}
