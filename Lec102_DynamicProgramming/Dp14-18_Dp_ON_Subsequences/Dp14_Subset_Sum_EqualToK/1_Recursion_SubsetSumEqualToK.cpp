#include <iostream>
#include <vector>
using namespace std;

bool subsetSumK(int index, int target, vector<int> &arr)
{
  if (target == 0)  // given Subset Reached the target
  {
    return true;
  }
  if (index == 0) // Is First element equal to target
  {
    return arr[0] == target;
  }

  bool notPick = subsetSumK(index - 1, target, arr);
  bool pick = false;
  if (target >= arr[index])
  {
    pick = subsetSumK(index - 1, target - arr[index], arr);
  }

  return pick || notPick;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  int k = 4;
  cout << "Subset Sum Equal To K: " << subsetSumK(arr.size() - 1, k, arr) << endl;
}