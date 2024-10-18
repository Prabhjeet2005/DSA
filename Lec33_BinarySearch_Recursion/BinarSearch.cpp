#include <iostream>
#include <array>
using namespace std;

// tc=>log2n
bool found(int *arr, int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return 0;
    }
    if (arr[mid] == target)
    {
        return 1;
    }
    if (arr[mid] < target)
    {
        return found(arr, mid + 1, e, target);
    }
    if (arr[mid] > target)
    {
        return found(arr, s, mid - 1, target);
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 5, 8};
    cout << "Enter Key: ";
    int target;
    cin >> target;
    int ans = found(arr, 0, 4, target);
    cout << ans << endl;
    return 0;
}