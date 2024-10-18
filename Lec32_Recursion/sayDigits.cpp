#include<iostream>
using namespace std;

// TC=> O(log10 n )

void sayDigit(int n, string arr[]){
    if(n==0){
        return;
    }
    int digit = n % 10;
    n /= 10;
    sayDigit(n,arr);
    cout << arr[digit] << " ";
}
int main(){
    string arr[10] = {
        "Zero",  // 0
        "One",   // 1
        "Two",   // 2
        "Three", // 3
        "Four",  // 4
        "Five",  // 5
        "Six",   // 6
        "Seven", // 7
        "Eight", // 8
        "Nine"   // 9
    };
    cout<<"Enter No.: ";
    int n;
    cin >> n;
    sayDigit(n,arr);
}