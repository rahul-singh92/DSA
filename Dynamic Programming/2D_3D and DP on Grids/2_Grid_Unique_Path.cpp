#include <iostream>
using namespace std;

// using recursive way
int recursive(int i, int j, int m, int n)
{
    int count = 0;
    if(i > m || j > n) return 0;
    if(i == m && j == n) return 1;
    if(j < n) count += recursive(i, j + 1, m, n);
    if(i < m) count += recursive(i + 1, j, m, n);
    return count;
}

// using memoization - top down
int func(int i, int j, vector<vector<int>>& dp)
{
    if(i == 0 && j == 0) return 1;
    // for out of bound as going top down
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int count = 0;
    count +=  func(i-1, j, dp);
    count += func(i, j-1, dp);
    return dp[i][j] = count;
}

int memo_way(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m - 1, n - 1, dp);
}

// Using tabulation - bottom up
int tabu_way(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // base condition
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}

// space optimisation way;
int spaceOp_way(int m, int n)
{
    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main()
{
    int m = 3, n = 2;
    // int ans = recursive(0, 0,m-1, n-1);
    // int ans = memo_way(m, n); Memoization way
    // int ans = tabu_way(m, n);
    int ans = spaceOp_way(m, n);
    cout<<ans<<endl;
}