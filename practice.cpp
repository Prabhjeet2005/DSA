#include <iostream>
#include <string>
#include <vector>
using namespace std;

void keypad(vector<string> &ans, string output, int index, string digits, string mapping[])
{
    if (index >= digits.size())
    {
        if (output.size() > 0)
            ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string alpha = mapping[number];
    for (int i = 0; i < alpha.size(); i++)
    {
        output.push_back(alpha[i]);
        keypad(ans, output, index + 1, digits, mapping);
        output.pop_back();
    }
}

int main()
{
    string digits = "25";
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypad(ans, output, index, digits, mapping);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "'" << ans[i] << "'" << ",";
    }
    cout << "]" << endl;
    return 0;
}
