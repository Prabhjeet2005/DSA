#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  int n = arr.size();

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 != 0)
  {
    cout << "Subset Doesnt Exist";
  }
  else
  {

    vector<bool>prev(sum/2+1,false),curr(sum/2+1,false);
      prev[0] = true;
    
    if (arr[0] <= sum / 2)
    {
      prev[arr[0]] = true;
    }
    curr[0] = true;

    for (int index = 1; index < n; index++)
    {
      for (int target = 1; target <= sum / 2; target++)
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
    cout << "Subset Exists or not: ";
    prev[sum / 2] == 1 ? cout << "Yes\n" : cout << "No\n";
  }
}