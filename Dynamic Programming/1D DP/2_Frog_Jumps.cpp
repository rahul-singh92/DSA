#include <iostream>
using namespace std;

// using memoization
int solve(int ind, const vector<int>& height, vector<int>& dp)
{
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int jumpTwo = INT_MAX;

    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

    if(ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int fj(vector<int>& heights)
{
    if(heights.empty()) return 0;

    int n = (int)heights.size();
    vector<int> dp(n, -1);

    return solve(n-1, heights, dp);
}

// using tabulation
int better_way(vector<int>& heights)
{
    if(heights.empty()) return 0;
    // here dp[i] is minimum energy to reach i
    vector<int> dp((int)heights.size(), INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= (int)heights.size(); i++)
    {
        int jumpOne = dp[i - 1] + abs(heights[i] - heights[i-1]);
        int jumpTwo = INT_MAX;

        if(i > 1)
        {
            jumpTwo = dp[i - 2] + abs(heights[i] - heights[i-2]);
        }

        dp[i] = min(jumpOne, jumpTwo);
    }
    return dp[heights.size()-1];
}

// tabulation space optmization
int best_way(vector<int>& heights)
{
    if(heights.empty()) return 0;

    int n = heights.size();

    if(n == 1) return 0;

    int prev1 = 0 , prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int jumpTwo = INT_MAX;

        int jumpOne = prev1 + abs(heights[i] - heights[i-1]);

        if(i > 1)
        {
            jumpTwo = prev2 + abs(heights[i] - heights[i-2]);
        }

        int cur_i = min(jumpOne, jumpTwo);

        prev2 = prev1;
        prev1 = cur_i;
    }
    return prev1;
}

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    // memoization
    // cout<<fj(heights)<<endl;

    // tabulation
    // cout<<better_way(heights)<<endl;

    // space optmisation
    cout<<best_way(heights)<<endl;
}

