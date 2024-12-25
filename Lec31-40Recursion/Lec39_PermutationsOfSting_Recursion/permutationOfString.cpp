#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string> nums, vector<vector<string>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]); //BACKTRACKING for CONSISTENCY
    }
}

int main()
{
    vector<string> nums = {"a", "b", "c"};
    vector<vector<string>> ans;
    int index = 0;
    solve(nums, ans, index);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "    ";
    }
    cout << endl;
    return 0;
}