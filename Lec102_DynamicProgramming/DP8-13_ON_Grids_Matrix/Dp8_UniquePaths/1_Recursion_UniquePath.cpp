#include <iostream>
#include <vector>
using namespace std;

// Tc -> O(2^(m + n))
// Sc -> O(Path Length) + O(Recursive Stack)

int totalUniquePath(int row, int col)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }

  int left = totalUniquePath(row, col - 1);
  int up = totalUniquePath(row - 1, col);

  return left + up;
}

int main()
{
  int m = 3;
  int n = 2;

  cout << "Total Possible Ways: " << totalUniquePath(m - 1, n - 1) << endl;
}