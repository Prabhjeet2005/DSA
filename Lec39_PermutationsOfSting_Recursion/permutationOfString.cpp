#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int>nums,vector<int>output,vector<vector<int>>&ans,int index){
    if(index>=nums.size()){
        if(output.size()>0){
            ans.push_back(output);
        }
        return;
    }
    int num=nums[index];
    permutation(nums, output, ans, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int index = 0;
    vector<int> output;
    permutation(nums, output, ans, index);
}