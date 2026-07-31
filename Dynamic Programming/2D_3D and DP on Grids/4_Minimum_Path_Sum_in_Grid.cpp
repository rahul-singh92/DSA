#include <iostream>
using namespace std;

// Using recursive way
int rec(vector<vector<int>>& arr, int i, int j)
{
    if(i == arr.size() - 1 && j == arr[0].size() - 1)
    {
        return arr[i][j];
    }
    if(i >= arr.size() || j >= arr[0].size()) return INT_MAX;
    int right = 0, down = 0;
    
    down = rec(arr, i+1, j);
    right = rec(arr, i, j+1);
    
    return arr[i][j] + min(down, right);
}

// Using Memoization way
int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j)
{
    if(i < 0 || j < 0) return INT_MAX;
    if(i == 0 && j == 0)
    {
        return arr[i][j];
    }

    if(dp[i][j] != -1) return dp[i][j];

    int up = solve(arr, dp, i-1, j);
    int left = solve(arr, dp, i, j-1);

    return dp[i][j] = arr[i][j] + min(up, left);
}

int memo_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), -1));
    return solve(arr, dp, arr.size() - 1, arr[0].size() - 1);
}

// Using tabulation way
int tabulation_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = arr[i][j];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];
            dp[i][j] = arr[i][j] + min(up, left);
        }
    }
    return dp[arr.size() - 1][arr[0].size() - 1];
}

int spacOp_way(vector<vector<int>>& arr)
{
    vector<int> prev(arr[0].size(), 0);

    for(int i = 0; i < arr.size(); i++)
    {
        vector<int> temp(arr[0].size(), 0);

        for(int j = 0; j < arr[0].size(); j++)
        {
            if(i == 0 && j == 0)
            {
                temp[j] = arr[i][j];
                continue;
            }

            int up = INT_MAX, left = INT_MAX;
            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j-1];

            temp[j] = arr[i][j] + min(up, left);
        }
        prev = temp;
    }
    return prev[arr[0].size() - 1];
}

int main()
{
    vector<vector<int>> arr = {{5,9,6},{11,5,2}};

    // int ans = rec(arr, 0, 0);
    // int ans = memo_way(arr);
    // int ans = tabulation_way(arr);
    int ans = spacOp_way(arr);
    cout<<ans<<endl;
}