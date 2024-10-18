#include <iostream>
#include <vector>
using namespace std;

// TC=>O(2^n)

void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> output, int index)
{

    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, ans, output, index + 1);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, ans, output, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, ans, output, index);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << " { ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << "} ,";
    }
    cout << endl;
    return 0;
}