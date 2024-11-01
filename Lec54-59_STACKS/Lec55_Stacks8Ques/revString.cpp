#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> st;
    string str = "Prabhjeet";

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    cout << ans;
    cout << endl;
    return 0;
}