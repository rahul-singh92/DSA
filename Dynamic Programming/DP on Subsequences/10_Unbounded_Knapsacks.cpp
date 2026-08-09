#include <iostream>
using namespace std;

int rec_way(vector<int>& wt, vector<int>& val, int target, int ind)
{
    if(ind == 0)
    {
        if(target % wt[0] == 0) return val[0] * (target / wt[0]);
        else {return 0;}
    }

    int notTake = rec_way(wt, val, target, ind - 1);
    int take = 0;
    if(wt[ind] <= target)
        take = val[ind] + rec_way(wt, val, target - wt[ind], ind);
    return max(take, notTake);
}

// memoization way
int solve_memoWay(vector<int>& wt, vector<int>& val, int target, vector<vector<int>>& dp, int ind)
{
    if(ind == 0)
    {
        if(target % wt[0] == 0) return val[0]*(target / wt[0]);
        else return 0;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = solve_memoWay(wt, val, target, dp, ind - 1);
    int take = 0;
    if(wt[ind] <= target)
        take = val[ind] + solve_memoWay(wt, val, target - wt[ind], dp, ind);
    return dp[ind][target] = max(take, notTake);
}

int memo_way(vector<int>& wt, vector<int>& val, int target)
{
    vector<vector<int>> dp(wt.size(), vector<int>(target + 1, -1));
    return solve_memoWay(wt, val, target, dp, wt.size() - 1);
}

// tabulation way
int tabu_way(vector<int>& wt, vector<int>& val, int target)
{
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for(int i = 0; i <= target; i++)
    {
        if(i % wt[0] == 0) dp[0][i] = val[0] * (i / wt[0]);
    }

    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 0; k <= target; k++)
        {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if(wt[ind] <= k)
                take = val[ind] + dp[ind][k - wt[ind]];
            dp[ind][k] = max(take, notTake);
        }
    }
    return dp[n-1][target];
}

int spaceOp_way(vector<int>& wt, vector<int>& val, int target)
{
    int n = wt.size();

    vector<int> prev(target + 1, 0);

    for(int i = 0; i <= target; i++)
    {
        if(i%wt[0] == 0) prev[i] = val[0] * (i / wt[0]);
    }

    for(int ind = 1; ind < n; ind++)
    {
        vector<int> curr(target + 1, 0);
        for(int k = 0; k <= target; k++)
        {
            int notTake = prev[k];
            int take = 0;
            if(wt[ind] <= k)
                take = val[ind] + curr[k - wt[ind]];
            curr[k] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 8;

    // int ans = rec_way(wt, val, W, wt.size() - 1);
    // int ans = memo_way(wt, val, W);
    // int ans = tabu_way(wt, val, W);
    int ans = spaceOp_way(wt, val, W);
    cout<<ans<<endl;
}