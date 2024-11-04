#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> firstk(int *arr, int size, int k)
{

    deque<int> dq;
    vector<int> ans;
    // First Window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i); //DEQUE maintains the index of -ve element
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    //REST OF WINDOWS
    for (int i = k; i < size; i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }

        if(arr[i]<0){
            dq.push_back(i);
        }

        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    int arr[5] = {-8, 2, 3, -6, 10};
    vector<int> ans;
    int size = 5;
    int k = 2;
    ans = firstk(arr, size, k);
    for (int i = 0; i<size; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}