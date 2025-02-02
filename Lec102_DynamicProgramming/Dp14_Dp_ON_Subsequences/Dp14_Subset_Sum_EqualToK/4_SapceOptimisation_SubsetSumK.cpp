#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> arr = {1, 2, 3, 4};
  int n = arr.size();
  int k = 4;

  vector<bool> prev(k + 1, false);
  prev[0] = true;
  prev[arr[0]] = true;

  for (int index = 1; index < n; index++)
  {
    vector<bool> curr(k + 1, false);
    curr[0] = true;
    for (int target = 1; target <= k; target++)
    {
      bool notPick = prev[target];
      bool pick = false;
      if (arr[index] <= target)
      {
        pick = prev[target - arr[index]];
      }
      curr[target] = pick || notPick;
    }
    prev = curr;
  }

  cout << "Subset Sum Equal to K Exists Or Not: " << prev[k] << endl;
}