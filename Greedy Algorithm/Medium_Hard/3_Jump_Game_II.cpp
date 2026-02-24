#include <iostream>
using namespace std;

int minJumps(vector<int>& nums, int position)
{
    if(position >= nums.size() - 1) return 0;

    if(nums[position] == 0) return INT_MAX;

    int minStep = INT_MAX;
    for(int jump = 1; jump <= nums[position]; jump++)
    {
        int subResult = minJumps(nums, position + jump);

        if(subResult != INT_MAX)
        {
            minStep = min(minStep, 1 + subResult);
        }
    }

    return minStep;
}

int bru_way(vector<int>& nums)
{
    return minJumps(nums, 0);
}

int bet_way(vector<int>& nums)
{
    int n = nums.size();

    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= nums[i] && i + j < n; j++)
        {
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    return dp[n-1];
}

int op_way(vector<int>& nums)
{
    int jump = 0, curEnd = 0, farthest = 0;

    for(int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, nums[i] + i);

        if(i == curEnd)
        {
            jump++;

            curEnd = farthest;
        }
    }
    return jump;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    int ans = op_way(nums);
    cout<<ans<<endl;
}