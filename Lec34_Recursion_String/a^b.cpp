#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b&1==1){ //is odd
        return a *( power(a, b / 2) * power(a, b / 2));
    }
    else{
        return (power(a, b / 2) * power(a, b / 2));
    }

}
int main(){
    cout << "Enter a & b: ";
    int a, b;
    cin >> a >> b;
    cout << "a^b : " << power(a, b)<<endl;
}