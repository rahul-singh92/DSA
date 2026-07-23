#include <iostream>
using namespace std;

// use memoization
int fj(int n, vector<int>& dp, vector<int>& heights, int k)
{
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int mmSteps = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        if(n - i >= 0)
        {
            int jump = fj(n-i, heights, dp, k) + abs(heights[n] - heights[n-i]);
            mmSteps = min(mmSteps, jump);
        }
    }
    return dp[n] = mmSteps;
}

int solve(int n,vector<int>& heights , int k)
{
    if(heights.empty()) return 0;
    vector<int> dp(n, -1);
    
    return fj(n-1, dp, heights, k);
}

// use tabulation
int better_solve(int n, vector<int>& heights, vector<int>& dp, int k)
{
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;

        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i-j]);

                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n-1];
}

int better_way(int n, vector<int>& heights,int k)
{
    vector<int> dp(n, -1);
    return better_solve(n, heights, dp, k);
}

int main()
{
    vector<int> heights = {10, 5, 20, 0, 15};
    int n = heights.size();
    int k = 2;
    //memoization
    // cout<<solve(n, heights, k);

    // tabulation
    cout<<better_way(n, heights, k);
}