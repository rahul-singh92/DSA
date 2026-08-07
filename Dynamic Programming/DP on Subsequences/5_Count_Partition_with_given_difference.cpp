#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int target, int i)
{
    if(target == 0) return 1;

    if(i == 0)
        return (arr[0] == target)?1:0;
    
    int notTake = rec_way(arr, target, i - 1);
    int take = 0;
    if(arr[i] <= target)
        take = rec_way(arr, target - arr[i], i - 1);
    return take + notTake;
}

// Memoization Way
int solve_memo(vector<int>& arr, vector<vector<int>>& dp, int target, int ind)
{
    if(target == 0) return 1;

    if(ind == 0) return (arr[0] == target)? 1: 0;

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memo(arr, dp, target, ind - 1);
    int take = 0;
    if(arr[ind] <= target)
        take = solve_memo(arr, dp, target - arr[ind], ind - 1);
    return dp[ind][target] = take + notTake;
}

int memo_way(vector<int>& arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return solve_memo(arr, dp, target, arr.size() - 1);
}

int tabulation_way(vector<int>& arr, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    dp[0][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 0; k <= target; k++)
        {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if(arr[ind] <= k)
                take = dp[ind - 1][k - arr[ind]];
            dp[ind][k] = take + notTake;
        }
    }
    return dp[n-1][target];
}

int spaceOp_way(vector<int>& arr, int target)
{
    vector<int> prev(target + 1, 0);

    prev[0] = 1;
    if(arr[0] <= target) prev[arr[0]] = 1;

    for(int ind = 1; ind < arr.size(); ind++)
    {
        vector<int> curr(target + 1, 0);
        curr[0] = 1;
        for(int k = 0; k <= target; k++)
        {
            int notTake = prev[k];
            int take = 0;
            if(arr[ind] <= k)
                take = prev[k - arr[ind]];
                
            curr[k] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    // subset 1 - subset 2 = diff
    // subset 1 + subset 2 = totSum 
    // Add both 2 * subset 1 = diff + totSum
    // subset 1 = (diff + totSum)/2
    // So we have to find number of subset whose sum is above target
    int totSum = 0;
    for(auto x: arr) totSum += x;
    int k = (diff + totSum) / 2;
    int ans = 0;
    if(diff <= totSum || (totSum + diff) % 2 == 0)
        // ans = rec_way(arr, k, arr.size() - 1);
        // ans = memo_way(arr, k);
        // ans = tabulation_way(arr, k);
        ans = spaceOp_way(arr, k);
    cout<<ans<<endl;
}