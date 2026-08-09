#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int target, int ind)
{
    if(ind == 0)
    {
        if(target % arr[0] == 0) return target / arr[0];
        else return 0;
    }

    int notTake = rec_way(arr, target, ind - 1);
    int take = 0;
    if(arr[ind] <= target)
        take = rec_way(arr, target - arr[ind], ind);
    return take + notTake;
}

// Memoization way
int solve_memoWay(vector<int>& arr, int target, vector<vector<int>>& dp, int ind)
{
    if(ind == 0)
        return (target % arr[0] == 0)?1:0;
    
    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memoWay(arr, target, dp, ind - 1);
    int take = 0;
    if(arr[ind] <= target)
        take = solve_memoWay(arr, target - arr[ind], dp, ind);
    return dp[ind][target] = take + notTake;
}

int memo_way(vector<int>& arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return solve_memoWay(arr, target, dp, arr.size() - 1);
}

// Tabulation way
int tabu_way(vector<int>& arr, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int i = 0; i <= target; i++)
        if(i % arr[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    
    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 0; k <= target; k++)
        {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if(arr[ind] <= k)
                take = dp[ind][k - arr[ind]];
            dp[ind][k] = take + notTake;
        }
    }
    return dp[n-1][target];
}

// space optimization way
int spaceOp_way(vector<int>& arr, int target)
{
    int n = arr.size();
    vector<int> prev(target + 1, 0);

    for(int i = 0; i <= target; i++)
        prev[i] = (target % arr[0] == 0) ? 1: 0;
    
    for(int ind = 1; ind < n; ind++)
    {
        vector<int> curr(target + 1, 0);
        for(int k = 0; k <= target; k++)
        {
            int notTake = prev[k];
            int take = 0;
            if(arr[ind] <= k)
                take = curr[k - arr[ind]];
            curr[k] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> coins = {2, 4, 10};
    int target = 10;

    // int ans = rec_way(coins, target, coins.size() - 1);
    // int ans = memo_way(coins, target);
    int ans = tabu_way(coins, target);
    cout<<ans<<endl;
}