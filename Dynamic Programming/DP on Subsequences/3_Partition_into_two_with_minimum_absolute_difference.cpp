#include <iostream>
using namespace std;

bool solve_memoWay(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
{
    // if target 0 then true
    if(target == 0) return true;

    // if all element done but still not found the target;
    if(ind == 0)
        return dp[ind][target] = (target == arr[0]);
    
    bool notTaken = solve_memoWay(ind - 1, target, arr, dp);

    bool taken = false;
    if(arr[ind] <= target)
        taken = solve_memoWay(ind - 1, target - arr[ind], arr, dp);
    
    return dp[ind][target] = notTaken || taken;
}

int memo_way(vector<int>& arr)
{
    int n = arr.size();

    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    for(int i = 0; i <= totSum; i++)
        bool dummy = solve_memoWay(n - 1, i, arr, dp);
    
    int mini = 1e9;
    for(int i = 0; i <= totSum; i++)
    {
        if(dp[n-1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }    
    return mini;
}

// Tabulation way
int tabu_way(vector<int>& arr)
{
    int n = arr.size();

    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    if(arr[0] <= totSum)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 1; k <= totSum; k++)
        {
            bool notTaken = dp[ind-1][k];

            bool taken = false;
            if(arr[ind] <= k)
                taken = dp[ind-1][k-arr[ind]];
            dp[ind][k] = taken || notTaken;
        }
    }

    int mini = 1e9;
    for(int i = 0; i <= totSum; i++)
    {
        if(dp[n-1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Space Optimization Way
int spaceOp_way(vector<int>& arr)
{
    int n = arr.size();

    int totSum = 0;
    for(auto x: arr)
        totSum += x;

    vector<bool> prev(totSum + 1, false);

    prev[0] = true;

    if(arr[0] <= totSum)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(totSum + 1, false);
        curr[0] = true;
        for(int k = 1; k <= totSum; k++)
        {
            bool notTaken = prev[k];

            bool taken = false;
            if(arr[ind] <= k)
                taken = prev[k - arr[ind]];
            
            curr[k] = taken || notTaken;
        }
        prev = curr;
    }

    int mini = 1e9;
    for(int i = 0; i <= totSum; i++)
    {
        if(prev[i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    // int ans = memo_way(arr);
    // int ans = tabu_way(arr);
    int ans = spaceOp_way(arr);
    cout<<ans<<endl;
}