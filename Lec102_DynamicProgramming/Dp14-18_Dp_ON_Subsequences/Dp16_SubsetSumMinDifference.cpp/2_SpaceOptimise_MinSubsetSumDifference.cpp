#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {2, 3, 7};
  int totalSum = 0;
  int n = arr.size();
  for(int i=0; i<n; i++){
    totalSum+=arr[i];
  }
  int k = totalSum;
  

  vector<bool> prev(k + 1, false);
  vector<bool> curr(k + 1, false);
  prev[0] = true;

  if (arr[0] <= k)
  {
    prev[arr[0]] = true;
  }

  for (int index = 1; index < n; index++)
  {
    curr[0] = true;
    for (int target = 1; target <= k; target++)
    {
      bool notpick = prev[target];
      bool pick = false;
      if (arr[index] <= target)
      {
        pick = prev[target - arr[index]];
      }
      curr[target] = pick || notpick;
    }
    prev = curr;
  }

  int mini = 1e9;
  for (int s1 = 0; s1 <= k / 2; s1++)
  {
    if (prev[s1] == true)
    {
      int s2 = k - s1;
      mini = min(mini, abs(s2 - s1));
    }
  }
  cout << "Min Subset Sum Difference : " << mini << endl;
}