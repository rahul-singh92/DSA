#include <iostream>
using namespace std;

int helper(vector<int>& coins, int rem, vector<int>& dp)
{
    if(rem == 0) return 0;

    if(rem < 0) return -1;
    
    if(dp[rem] != -2) return dp[rem];

    int mini = INT_MAX;

    for(int coin: coins)
    {
        int res = helper(coins, rem - coin, dp);

        if(res >= 0 && res < mini) mini = 1 + res;
    }

    dp[rem] = (mini == INT_MAX) ? -1 : mini;
    return dp[rem];
}

int memoization(vector<int>& coins, int amount)
{
    // -2 means not calculated yet
    vector<int> dp(amount + 1, -2);

    return helper(coins, amount, dp);
}

int tabulation(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
    {
        for(int coin: coins)
        {
            if(i - coin >= 0 && dp[i - coin] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int op_way(vector<int>& coins, int amount)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0);

    for(int i = 0; i <= amount; i++)
    {
        if(i % coins[0] == 0) prev[i] = i / coins[0];
        else prev[i] = 1e9;
    }

    for(int ind = 1; ind < n; ind++)
    {
        for(int target = 0; target <= amount; target++)
        {
            int notTake = prev[target];

            int take = 1e9;
            if(coins[ind] <= target) take = 1 + cur[target - coins[ind]];

            cur[target] = min(notTake, take);
        }

        prev = cur;
    }

    int ans = prev[amount];

    if(ans >= 1e9) return -1;

    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int ans = op_way(coins, amount);

    cout<<ans<<endl;
}