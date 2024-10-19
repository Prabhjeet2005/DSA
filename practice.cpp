#include <iostream>
#include<string>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int num;
        cin >> num;
        string ans(num, '0');
        for (int i = 0; i < ans.length();i++){
            if(i&1){
            ans[i] = '1'; 
            }
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}
