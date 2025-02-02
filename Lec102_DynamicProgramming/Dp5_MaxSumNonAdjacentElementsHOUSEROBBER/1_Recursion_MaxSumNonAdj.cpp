#include <iostream>
#include <vector>
using namespace std;

int nonAdjSum(int n, vector<int> &arr)
{
  if (n == 0) // It can either reach 0 or -1 index ,as f(n-2) of 1st index will go to -1
  {
    return arr[0];
  }
  if (n < 0)
  {
    return 0;
  }

  int pick = arr[n] + nonAdjSum(n - 2, arr);
  int notPick = 0 + nonAdjSum(n - 1, arr);

  return max(pick, notPick);
}

int main()
{
  vector<int> arr = {2, 1, 4, 9}; // Output -> 11
  int n = arr.size(); //Adjust n Later

  cout << "Max Non Adj Sum: " << nonAdjSum(n - 1, arr) << endl; // Adjust n
}