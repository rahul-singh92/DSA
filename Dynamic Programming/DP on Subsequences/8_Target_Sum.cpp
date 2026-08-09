#include <iostream>
using namespace std;

// in this S1 + S2 = target, S1 + S2 = totdum, so S2 = (totSum - target) / 2;
// Recursive Way
int solve_recWay(vector<int>& arr, int target, int ind)
{
    if(target == 0)
        return 1;
    if(ind == 0)
        return (arr[0] == target)?1:0;
    
    int notTake = solve_recWay(arr, target, ind - 1);
    int take = 0;
    if(arr[ind] <= target)
        take = solve_recWay(arr, target - arr[ind], ind - 1);
    return take + notTake;
}

int recursive_way(vector<int>& arr, int target)
{
    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    if(totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;
    
    int subsetSum = (totSum - target) / 2;

    return solve_recWay(arr, subsetSum, arr.size() - 1);
}

// Memoization Way
int solve_memoWay(vector<int>& arr, int target, int ind, vector<vector<int>>& dp)
{
    if(target == 0)
        return 1;
    
    if(ind == 0)
        return (target == arr[0])?1:0;
    
    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memoWay(arr, target, ind - 1, dp);
    int take = 0;
    if(arr[ind] <= target)
        take = solve_memoWay(arr, target - arr[ind], ind - 1, dp);
    return dp[ind][target] = take + notTake;
}

int memo_way(vector<int>& arr, int target)
{
    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    if(totSum - target < 0 || (totSum - target)%2 != 0)
        return 0;
    
    int subsetSum = (totSum - target) / 2;
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return solve_memoWay(arr, subsetSum, arr.size() - 1, dp);
}

// tabulation way
int tabu_way(vector<int>& arr, int target)
{
    int n = arr.size();

    int totSum = 0;
    for(int x: arr) totSum += x;

    if(totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;
    
    int newTarget = (totSum - target) / 2;

    vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));

    dp[0][0] = 1;
    if(arr[0] <= newTarget) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 0; k <= newTarget; k++)
        {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if(arr[ind] <= k)
                take = dp[ind - 1][k - arr[ind]];
            
            dp[ind][k] = take + notTake;
        }
    }
    return dp[n-1][newTarget];
}

// Space Optimization way
int spaceOp_way(vector<int>& arr, int target)
{
    int n = arr.size();
    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    if(totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;

    int newTarget = (totSum - target) / 2;
    vector<int> prev(newTarget + 1, 0);

    prev[0] = 1;
    if(arr[0] <= newTarget) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++)
    {
        vector<int> curr(newTarget + 1, 0);
        curr[0] = 1;
        for(int k = 0; k <= newTarget; k++)
        {
            int notTake = prev[k];
            int take = 0;
            if(arr[ind] <= k)
                take = prev[k-arr[ind]];
            curr[k] = take + notTake;
        }
        prev = curr;
    }
    return prev[newTarget];
}

int main()
{
    vector<int> arr = {1,1,1,1,1};
    int target = 3;

    // int ans = recursive_way(arr, target);
    // int ans = memo_way(arr, target);
    // int ans = tabu_way(arr, target);
    int ans = spaceOp_way(arr, target);
    cout<<ans<<endl;
}