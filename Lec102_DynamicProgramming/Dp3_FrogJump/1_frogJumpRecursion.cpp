#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
Problem statement
There is a frog on the '1st' step of an 'N' stairs long staircase.
The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height
of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair,
the energy lost in the jump is given by absolute value
of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase,
 he can jump either to '(i+1)th' stair or to '(i+2)th' stair.
 Your task is to find the minimum total energy used by the frog to
  reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10],
the answer 20 as the frog can jump from 1st stair to
2nd stair (|20-10| = 10 energy lost) and then a jump from
2nd stair to last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20.

Sample Input 1:
10 20 30 10

Sample Output 1:
20

*/

int minCost(int n, vector<int> &steps)
{
  if (n == 0)
  {
    return 0;
  }
  int left = minCost(n - 1, steps) + abs(steps[n] - steps[n - 1]);
  int right;
  if (n > 1)
  {
    right = minCost(n - 2, steps) + abs(steps[n] - steps[n - 2]);
  }
  else
  {
    right = INT_MAX;
  }
  return min(left, right);
}

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size();
  cout << "Min Cost: " << minCost(n - 1, steps) << endl;
}