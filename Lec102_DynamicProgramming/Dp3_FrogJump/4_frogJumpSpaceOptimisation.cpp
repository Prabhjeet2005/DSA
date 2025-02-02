#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> steps = {10, 20, 30, 10};
  int n = steps.size() - 1;

  int prev1 = abs(steps[1] - steps[0]);
  int prev2 = 0;

  for (int i = 2; i <= n; i++)
  {
    int curri = min(prev1 + abs(steps.at(i) - steps[i - 1]), prev2 + abs(steps.at(i) - steps[i - 2]));
    prev2 = prev1;
    prev1 = curri;
  }
  cout << "Min Cost: " << prev1 << endl;
}