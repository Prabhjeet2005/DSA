#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>&arr){
  int prev2 = 0;
  int prev1 = arr[0];
  for (int i = 1; i < arr.size(); i++){
    int pick = arr[i] + prev2;
    int notPick = 0 + prev1;

    int curri = max(pick,notPick);

    prev2 = prev1;
    prev1 = curri;
  }
  return prev1;
}

int main(){
  vector<int> houses = {1, 3, 2, 1};
  int n = houses.size();

  vector<int>temp1;
  vector<int>temp2;

  if (houses.size() == 1)
  {
    return houses[0];
  }

  for (int i = 0; i<n; i++){
    if(i!=0){
      temp2.push_back(houses[i]);
    }
    if(i!=n-1){
      temp1.push_back(houses[i]);
    }
  }

  int ans1 = solve(temp1);
  int ans2 = solve(temp2);
  cout << "Max NonAdj Sum: " << max(ans1, ans2) << endl;
}