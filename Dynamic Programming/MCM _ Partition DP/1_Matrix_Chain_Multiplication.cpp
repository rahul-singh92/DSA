#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int i, int j)
{
    if(i == j) return 0;

    int minCost = INT_MAX;

    // create partitions
    for(int k = i; k < j; k++)
    {
        int cost1 = rec_way(arr, i, k);
        int cost2 = rec_way(arr, k + 1, j);

        int mul = arr[i - 1] * arr[k] * arr[j];

        int totalCost = cost1 + cost2 + mul;

        minCost = min(minCost, totalCost);
    }
    return minCost;
}

int solve_memoWay(vector<int>& arr, int i, int j, vector<vector<int>>& dp)
{
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for(int k = i; k < j; k++)
    {
        int cost1 = solve_memoWay(arr, i, k, dp);
        int cost2 = solve_memoWay(arr, k + 1, j, dp);

        int costMul = arr[i - 1] * arr[k] * arr[j];

        int totalCost = cost1 + cost2 + costMul;
        mini = min(mini, totalCost);
    }
    return dp[i][j] = mini;
}

int memo_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    return solve_memoWay(arr, 1, arr.size() - 1, dp);
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};

    // int ans = rec_way(arr, 1, arr.size() - 1);
    int ans = memo_way(arr);
    cout<<ans<<endl;
}