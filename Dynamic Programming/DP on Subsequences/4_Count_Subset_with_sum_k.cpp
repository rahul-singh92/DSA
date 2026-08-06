#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int k, int i)
{
    if(k == 0) return 1;

    if(i == 0)
    {
        return (arr[0] == k? 1: 0);
    }

    int notTake = rec_way(arr, k, i - 1);
    int take = 0;
    if(arr[i] <= k)
        take = rec_way(arr, k - arr[i], i - 1);

    return take + notTake;
}

// Memoization way
int solve_memoWay(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
{
    if(target == 0) return 1;

    if(ind == 0)
        return (arr[0] == target)?1:0;
    
    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memoWay(ind - 1, target, arr, dp);
    int take = 0;
    if(arr[ind] <= target)
        take = solve_memoWay(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take + notTake;
}

int memo_way(vector<int>& arr, int k)
{
    int n = arr.size();

    vector<vector<int>> dp(arr.size(), vector<int>(k+1, -1));
    return solve_memoWay(arr.size() - 1, k, arr, dp);
}

int tabu_way(vector<int>& arr, int k)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    // make sum 0
    dp[0][0] = 1;

    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int target = 0; target <= k; target++)
        {
            int notTake = dp[i-1][target];
            int take = 0;
            if(arr[i] <= target)
                take = dp[i-1][target - arr[i]];
            dp[i][target] = take + notTake;
        }
    }
    return dp[n-1][k];
}

int spaceOp(vector<int>& arr, int k)
{
    int n = arr.size();

    vector<int> prev(k+1, 0);
    prev[0] = 1;

    if(arr[0] <= k) prev[arr[0]] += 1;

    for(int i = 1; i < n; i++)
    {
        vector<int> curr(k+1, 0);
        curr[0] = 1;
        for(int target = 0; target <= k; target++)
        {
            int notTake = prev[target];

            int take = 0;
            if(arr[i] <= target)
                take = prev[target - arr[i]];
            curr[target] = take + notTake;
        }
        prev = curr;
    }
    return prev[k];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    // int ans = rec_way(arr, k, arr.size() - 1);
    // int ans = memo_way(arr, k);
    int ans = spaceOp(arr, k);
    cout<<ans<<endl;
}