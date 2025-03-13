#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  int n = arr.size();
  int k = 4;

  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  // Base Case
  for(int i = 0; i<n; i++){
    dp[i][0] = true;
  }
  dp[0][arr[0]] = true;

  for(int index = 1; index < n; index++){
    for(int target = 1; target <= k; target++){
      bool notPick = dp[index-1][target];
      bool pick = false;
      if( arr[index] <= target ){
        pick = dp[index-1][target - arr[index]];
      }
      dp[index][target] = pick || notPick;
    }
  }
  cout<<"Subset Exists Or NOT: "<<dp[n-1][k]<<endl;
}