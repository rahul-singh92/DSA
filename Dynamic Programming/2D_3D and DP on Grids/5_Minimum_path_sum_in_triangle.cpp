#include <iostream>
using namespace std;

// Using recursive way
int rec_way(vector<vector<int>>& arr, int i, int j)
{
    if(i == arr.size() - 1)
    {
        return arr[i][j];
    }

    int down = rec_way(arr, i + 1, j);
    int diag = rec_way(arr, i + 1, j + 1);

    return arr[i][j] + min(down, diag);
}

//Using memoization
int solve(vector<vector<int>>& arr, vector<vector<int>>& dp, int i, int j)
{
    if(dp[i][j] != -1) return dp[i][j];

    if(i == arr.size() - 1)
    {
        return arr[i][j];
    }

    int down = solve(arr, dp, i+1, j);
    int diag = solve(arr, dp, i+1, j+1);

    return dp[i][j] = arr[i][j] + min(down, diag);
}

int memo_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    return solve(arr, dp, 0, 0);
}

// Using tabulation way
int tabu_way(vector<vector<int>>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

    for(int i = 0; i < arr.size(); i++)
    {
        dp[arr.size() - 1][i] = arr[arr.size() - 1][i];
    }

    for(int i = arr.size() - 2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int down = dp[i+1][j];
            int diag = dp[i+1][j+1];

            dp[i][j] = arr[i][j] + min(down, diag);
        }
    }
    return dp[0][0];
}

// Using space optimization
int spaceOp_way(vector<vector<int>>& arr)
{
    vector<int> front(arr.size(), 0);
    vector<int> curr(arr.size(), 0);

    for(int i = 0; i < arr.size(); i++)
    {
        front[i] = arr[arr.size() - 1][i];
    }

    for(int i = arr.size() - 2; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int down = front[j];
            int diag = front[j+1];

            curr[j] = arr[i][j] + min(down, diag);
        }
        front = curr;
    }
    return front[0];
}

int main()
{
    vector<vector<int>> arr = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};

    // int ans = rec_way(arr, 0, 0);
    // int ans = memo_way(arr);
    // int ans = tabu_way(arr); 
    int ans = spaceOp_way(arr);
    cout<<ans<<endl;
}