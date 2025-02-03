#include <iostream>
#include <vector>
using namespace std;

bool subsetSumEqual(int index, int target, vector<int> &arr)
{
  if (target == 0)
  {
    return true;
  }
  if (index == 0)
  {
    return arr[0] == target;
  }

  bool notPick = subsetSumEqual(index - 1, target, arr);
  bool pick = false;
  if (arr[index] <= target)
  {
    pick = subsetSumEqual(index - 1, target - arr[index], arr);
  }
  return pick || notPick;
}

int main()
{
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  int n = arr.size();
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  if (sum % 2 == 0)
  {
    if (subsetSumEqual(n - 1, sum / 2, arr))
    {
      cout <<"Subset Sum Exists" << endl;
    }
    else
    {
      cout <<"Subset Not Possible" << endl;
    }
  }
  else
  {
    cout <<"Subset Not Possible" << endl;
  }
}
