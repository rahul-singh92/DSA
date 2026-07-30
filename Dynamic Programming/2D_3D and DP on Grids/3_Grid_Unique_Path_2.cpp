#include <iostream>
using namespace std;

// using recursive way
int recursive_way(vector<vector<int>>& arr, int i, int j, int n, int m)
{
    int count = 0;
    if(i == n && j == m)
    {
       return 1; 
    }

    if(i > n && j > m) return 0;

    if(i < n && arr[i+1][j] == 0)
    {
        count += recursive_way(arr, i+1, j, n, m);
    }
    if(j < m && arr[i][j+1] == 0)
    {
        count+= recursive_way(arr, i, j+1, n, m);
    }
    return count;
}

// Using Memoization - Top down
int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j)
{
    if(i == 0 && j == 0) return 1;

    if(i < 0 || j < 0 || arr[i][j] == 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int count = 0;
    count += solve(arr, dp, i-1, j);
    count += solve(arr, dp, i, j-1);
    return dp[i][j] = count;
}

int memoization_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), -1));
    return solve(arr, dp, arr.size() - 1, arr[0].size() - 1);
}

// Using Tabulation - bottom up
int tabu_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            if(arr[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }

            int up = 0, left = 0;
            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
    return dp[arr.size() - 1][arr[0].size() - 1];
}

// Using space optimization
int space_op(vector<vector<int>>& arr)
{
    int n = arr[0].size();
    vector<int> prev(n, 0), curr(n, 0);

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] == 1)
            {
                curr[j] = 0;
                continue;
            }
            if(i == 0 && j == 0)
            {
                curr[j] = 1;
                continue;
            }
            
            int up = 0, left = 0;

            if(i > 0) up = prev[j];
            if(j > 0) left = curr[j - 1];

            curr[j] = up + left;
        }
        prev = curr;
    }
    return prev[arr.size() - 1];
}

int main()
{
    vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // int ans = recursive_way(arr, 0, 0, arr.size() - 1, arr[0].size() - 1);
    // int ans = memoization_way(arr);
    // int ans = tabu_way(arr);
    int ans = space_op(arr);
    cout<<ans<<endl;
}