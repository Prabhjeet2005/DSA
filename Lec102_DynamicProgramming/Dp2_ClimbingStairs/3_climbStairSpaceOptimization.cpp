#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n = 4;
  const unsigned int M = 1e9 + 7;

  int prev1 = 1;
  int prev2 = 1;
  for (int i = 2; i <= n; i++)
  {
    int curri = (prev1 % M + prev2 % M) % M;
    prev2 = prev1;
    prev1 = curri;
  }
  cout << prev1 << endl;
}