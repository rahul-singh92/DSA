#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int i, int j)
{
    if(i > j) return 0;

    int maxi = INT_MIN;
    for(int k = i; k <= j; k++)
    {
        int a1 = (i - 1 < 0) ? 1: arr[i - 1];
        int a2 = (j + 1 >= arr.size()) ? 1: arr[j + 1];
        int rem1 = a1 * arr[k] * a2;
        int rem2 = rec_way(arr, i , k - 1) + rec_way(arr, k + 1, j);

        maxi = max(maxi,rem1 + rem2);
    }
    return maxi;
}

// or 

int solve_recWay(vector<int>& arr, int i, int j)
{
    if(i > j) return 0;

    int maxi = INT_MIN;

    for(int k = i; k <= j; k++)
    {
        int coins = arr[i - 1] * arr[k] * arr[j + 1];
        int rem = solve_recWay(arr, i, k - 1) + solve_recWay(arr, k + 1, j);
        maxi = max(maxi, coins + rem);
    }
    return maxi;
}

int rec_way2(vector<int>& arr)
{
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    return solve_recWay(arr, 1, n);
}

int solve_memoWay(vector<int>& arr, vector<vector<int>>& dp, int i, int j)
{
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;
    for(int k = i; k <= j; k++)
    {
        int cost = arr[i - 1] * arr[k] * arr[j + 1];
        int rem = solve_memoWay(arr, dp, i , k - 1) + solve_memoWay(arr, dp, k + 1, j);

        maxi = max(maxi, cost + rem);
    }

    return dp[i][j] = maxi;
}

int memo_way(vector<int>& arr)
{
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

    return solve_memoWay(arr, dp, 1, arr.size() - 2);
}

int tabu_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size() + 2, vector<int>(arr.size() + 2, 0));

    arr.push_back(1);
    arr.insert(arr.begin(), 1);

    for(int i = arr.size() - 2; i >= 1; i--)
    {
        for(int j = i; j <= arr.size() - 2; j++)
        {
            int maxi = INT_MIN;
            for(int k = i; k <= j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j + 1];
                int rem = dp[i][k - 1] + dp[k + 1][j];

                maxi = max(maxi, cost + rem);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][arr.size() - 2];
}

int main()
{
    vector<int> arr = {3, 1, 5, 8};

    // int ans = rec_way(arr, 0, arr.size() - 1);
    // int ans = rec_way2(arr);
    // int ans = memo_way(arr);
    int ans = tabu_way(arr);
    cout<<ans<<endl;
}