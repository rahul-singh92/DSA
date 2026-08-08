#include <iostream>
using namespace std;

int recursive_way(vector<int>& coins, int target, int ind)
{
    if(ind == 0)
    {
        if(target % coins[0] == 0) return target/coins[0];
        else return 1e8;
    }

    int notTake = recursive_way(coins, target, ind - 1);

    int take = 1e8;
    if(coins[ind] <= target) take = 1 + recursive_way(coins, target - coins[ind], ind);

    return min(take, notTake);
}

// Memoization way
int solve_memoWay(vector<int>& coins, int target, vector<vector<int>>& dp, int ind)
{
    if(ind == 0)
    {
        if(target % coins[0] == 0) return target / coins[0];
        else return 1e8;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memoWay(coins, target, dp, ind - 1);
    int take = 1e8;
    if(coins[ind] <= target)
        take = 1 + solve_memoWay(coins, target - coins[ind], dp, ind);
    return dp[ind][target] = min(take, notTake);
}

int memo_way(vector<int>& coins, int target)
{
    vector<vector<int>> dp(coins.size(), vector<int>(target + 1, -1));
    return solve_memoWay(coins, target, dp, coins.size() - 1);
}

// int tabulation way
int tabu_way(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int i = 0; i <= target; i++)
        if(i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else dp[0][i] = 1e8;
    
    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 0; k <= target; k++)
        {
            int notTake = dp[ind - 1][k];

            int take = 1e8;
            if(coins[ind] <= k)
                take = 1 + dp[ind][k - coins[ind]];

            dp[ind][k] = min(take, notTake);
        }
    }
    return dp[n-1][target];
}

int spaceOp_way(vector<int>& coins, int target)
{
    int n = coins.size();
    vector<int> prev(target + 1, 0);

    for(int i = 0; i <= target; i++)
        if(i % coins[0] == 0) prev[i] = i / coins[0];
        else prev[i] = 1e8;
    
    for(int ind = 1; ind < n; ind++)
    {
        vector<int> curr(target + 1, 0);
        for(int k = 0; k <= target; k++)
        {
            int notTake = prev[k];

            int take = 1e8;
            if(coins[ind] <= k)
                take = 1 + curr[k - coins[ind]];
            
            curr[k] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int k = 11;

    // int ans = recursive_way(coins, k, coins.size() - 1);
    // int ans = memo_way(coins, k);
    // int ans = tabu_way(coins, k);
    int ans = spaceOp_way(coins, k);
    cout<<ans<<endl;
}