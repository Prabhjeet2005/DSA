#include<iostream>
using namespace std;
int checkP(string str,int i, int j){
    while(i<str.length()/2){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    cout << "Enter String: ";
    string str;
    cin>>str;
    int ans = checkP(str, 0, str.length() - 1);
    if(ans==0){
        cout<<"Not Palindrome"<<endl;
    }else{
        cout << "Palindrome" << endl;
    }
}