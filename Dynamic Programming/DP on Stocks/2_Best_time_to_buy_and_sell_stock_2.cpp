#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int buy, int ind)
{
    if(ind == arr.size()) return 0;

    int profit = 0;

    if(buy)
    {
        profit += max(-arr[ind] + rec_way(arr, 0, ind + 1), rec_way(arr, 1, ind + 1));
    }
    else
    {
        profit += max(arr[ind] + rec_way(arr, 1, ind + 1), rec_way(arr, 0, ind + 1));
    }
    return profit;
}

int solve_memoWay(vector<int>& arr, vector<vector<int>>& dp, int buy, int ind)
{
    if(ind == arr.size()) return 0;

    int profit = 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy)
    {
        profit = max(-arr[ind] + solve_memoWay(arr, dp, 0, ind + 1), solve_memoWay(arr, dp, 1, ind + 1));
    }
    else 
    {
        profit = max(arr[ind] + solve_memoWay(arr, dp, 1, ind + 1), solve_memoWay(arr, dp, 0, ind + 1));
    }
    return dp[ind][buy] = profit;
}

int memo_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(2, -1));
    return solve_memoWay(arr, dp, 1, 0);
}

int tabu_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(2, 0));

    // no stock left then profit is 0
    dp[arr.size()][0] = dp[arr.size()][1] = 0;

    int profit;
    for(int ind = arr.size() - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            if(buy == 0)
            {
                profit = max(dp[ind + 1][0], -arr[ind] + dp[ind + 1][1]);
            }
            if(buy == 1)
            {
                profit = max(dp[ind + 1][1], arr[ind] + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}

int opWay(vector<int>& arr)
{
    vector<int> ahead(2, 0);
    vector<int> cur(2, 0);

    ahead[0] = ahead[1] = 0;

    int profit = 0;
    for(int ind = arr.size() - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            if(buy == 0)
            {
                profit = max(ahead[0], -arr[ind] + ahead[1]);
            }
            if(buy == 1)
            {
                profit = max(ahead[1], arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return cur[0];
}

int main()
{
    vector<int> arr = {7,1,5,3,6,4};

    // int ans = rec_way(arr, 1, 0);
    // int ans = memo_way(arr);
    // int ans = tabu_way(arr);
    int ans = opWay(arr);
    cout<<ans<<endl;
}