#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {1, 1, 4, 5};
  int t = 5;
  int n = arr.size();
  vector<int> prev(t + 1, 0);
  vector<int> curr(t + 1, 0);

  prev[0] = 1;
  if (arr[0] <= t)
  {
    prev[arr[0]] = 1;
  }

  for (int index = 1; index < n; index++)
  {
    curr[0] = 1;
    for(int target = 1; target <= t; target++){
      int notpick = prev[target];
      int pick = 0;
      if(arr[index] <= target){
        pick = prev[target - arr[index]];
      }
      curr[target] = pick + notpick;
    }
    prev = curr;
  }

  cout<<"Count of Subsets Sum Equal To K: "<<prev[t]<<endl;
}