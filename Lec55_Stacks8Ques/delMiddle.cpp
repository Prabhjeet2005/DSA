#include<iostream>
#include<stack>
using namespace std;

void delMid(stack<int> &st, int count ,int size){
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    delMid(st, count + 1, size);
    st.push(num);
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    delMid(st,0,5);

    for (int i = 0; i < 4; i++){
        cout<<st.top()<<endl;
        st.pop();
    }
}