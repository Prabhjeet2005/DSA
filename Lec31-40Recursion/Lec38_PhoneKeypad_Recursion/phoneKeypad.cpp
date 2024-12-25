#include<iostream>
#include<vector>
#include<string>
using namespace std;

void keypad(vector<string> &ans, string output, string mapping[], int index, string ques){
    if(index>=ques.size()){
        if(output.size()>0){
            ans.push_back(output);
        }
        return;
    }
    int num = ques[index] - '0';
    string alphabets = mapping[num];
    for (int i = 0; i < alphabets.size(); i++)
    {
        output.push_back(alphabets[i]);
        keypad(ans, output, mapping, index + 1, ques);
        output.pop_back();
    }
}

int main(){
    string ques;
    cout << "Enter String: ";
    cin >> ques;
    if(ques.size()==0){
        cout << "";
    }
    vector<string> ans;
    string output="";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    keypad(ans, output, mapping, index, ques);
    for (int i = 0; i < ans.size(); i++){
        cout << "'" << ans[i] << "'" << " ";
    }
    cout << endl;
}