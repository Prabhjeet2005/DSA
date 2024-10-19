#include<iostream>
using namespace std;
class A{
    public:
    void hello(){
        cout << "Saying Hello..." << endl;
    }
    void hello(int n){
        cout << "Say Hello Again" << endl;
    }
};
int main(){
    A a1;
    a1.hello();
}