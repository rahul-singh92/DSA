#include <iostream>
using namespace std;

// memoization
int solve(vector<int>& nums, vector<int>& dp, int n)
{
    // index negative so no need to pick
    if(n < 0) return 0;

    // if at first value return it;
    if(n == 0) return nums[0];

    if(dp[n] != -1) return dp[n];

    int pick = nums[n] + solve(nums, dp, n - 2);

    int notPick = solve(nums, dp, n - 1);

    return dp[n] = max(pick, notPick);
}

int memo(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, dp, n-1);
}


// use tabulation
int better_way(vector<int>& nums)
{
    int n = nums.size();
    
    if(nums.size() == 1) return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++)
    {
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

// spcae optimisation
int maxSum(vector<int>& nums) {
    if (nums.empty()) return 0;

    int prev2 = 0;
    int prev = nums[0];

    for (int i = 1; i < nums.size(); i++) 
    {
        int include = nums[i] + prev2;

        int exclude = prev;

        int curr = max(include, exclude);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    // memoization
    // cout<<memo(nums);

    // tabulation
    cout<<better_way(nums);
}