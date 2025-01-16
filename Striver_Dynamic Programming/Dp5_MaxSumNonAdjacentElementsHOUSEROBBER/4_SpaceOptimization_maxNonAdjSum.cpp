#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> arr = {2, 1, 4, 9}; // Output->11
  int n = arr.size();

  int prev2 = 0;
  int prev1 = arr[0]; 

  for (int i = 1; i < n; i++)
  {
    int pick = arr[i] + prev2;
    int notPick = 0 + prev1;

    int curri = max(pick, notPick);
    prev2 = prev1;
    prev1 = curri;
  }

  cout << "Max Non Adj Sum: " << prev1 << endl;
}