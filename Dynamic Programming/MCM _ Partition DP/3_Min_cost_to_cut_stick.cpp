#include <iostream>
using namespace std;

int solve_recWay(vector<int>& arr, int i, int j)
{
    if(i > j) return 0;

    int mini = INT_MAX;
    for(int k = i; k <= j; k++)
    {
        int ans = arr[j + 1] - arr[i - 1]
                  + solve_recWay(arr, i, k - 1)
                  + solve_recWay(arr, k + 1, j);
        mini = min(mini, ans);
    }
    return mini;
}

int rec_way(vector<int>& arr, int n)
{
    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    sort(arr.begin(), arr.end());
    return solve_recWay(arr, 1, arr.size() - 2);
}

int solve_memoWay(vector<int>& arr, int i, int j, vector<vector<int>>& dp)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k = i; k <= j; k++)
    {
        int ans = arr[j + 1] - arr[i - 1]
                  + solve_memoWay(arr, i, k - 1, dp)
                  + solve_memoWay(arr, k + 1, j, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int memo_way(vector<int>& arr, int n)
{
    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    sort(arr.begin(), arr.end());
    
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

    return solve_memoWay(arr, 1, arr.size() - 2, dp);
}

int tabu_way(vector<int>& arr, int n)
{
    arr.push_back(n);
    arr.insert(arr.begin(), 0);

    sort(arr.begin(), arr.end());

    vector<vector<int>> dp(arr.size() + 2, vector<int>(arr.size() + 2, 0));

    for(int i = arr.size() - 2; i >= 1; i--)
    {
        for(int j = i; j <= arr.size() - 2; j++)
        {
            int mini = INT_MAX;
            for(int k = i; k <= j; k++)
            {
                int ans = arr[j + 1] - arr[i - 1]
                          + dp[i][k - 1]
                          + dp[k + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][arr.size() - 2];
}

int main()
{
    vector<int> arr = {1, 3, 4, 5};
    int n = 7;

    // int ans = rec_way(arr, n);
    // int ans = memo_way(arr, n);
    int ans = tabu_way(arr, n);
    cout<<ans<<endl;
}