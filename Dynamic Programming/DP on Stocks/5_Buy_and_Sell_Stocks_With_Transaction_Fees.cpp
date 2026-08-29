#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int buy, int ind, int fee)
{
    if(ind == arr.size()) return 0;

    int profit = 0;
    if(buy)
    {
        profit = max(-arr[ind] + rec_way(arr, 0, ind + 1, fee), rec_way(arr, 1, ind + 1, fee));
    }
    else
    {
        profit = max(arr[ind] - fee + rec_way(arr, 1, ind + 1, fee), rec_way(arr, 0, ind + 1, fee));
    }
    return profit;
}

int solve_memoWay(vector<int>& arr, vector<vector<int>>& dp, int buy, int ind, int fee)
{
    if(ind == arr.size()) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy)
    {
        profit = max(-arr[ind] + solve_memoWay(arr, dp, 0, ind + 1, fee), solve_memoWay(arr, dp, 1, ind + 1, fee));
    }
    else
    {
        profit = max(arr[ind] - fee + solve_memoWay(arr, dp, 1, ind + 1, fee), solve_memoWay(arr, dp, 0, ind + 1, fee));
    }
    return dp[ind][buy] = profit;
}

int memo_way(vector<int>& arr, int fee)
{
    vector<vector<int>> dp(arr.size(), vector<int>(2, -1));
    return solve_memoWay(arr, dp, 1, 0, fee);
}

int tabu_way(vector<int>& arr, int fee)
{
    int n = arr.size();
    vector<vector<int>> dp(arr.size() + 1, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            int profit;
            if(buy)
            {
                profit = max(-arr[ind] + dp[ind+1][0], dp[ind+1][1]);
            }
            else
            {
                profit = max(arr[ind] - fee + dp[ind+1][1], dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

int spaceOp_way(vector<int>& arr, int fee)
{
    int n = arr.size();
    vector<int> cur(2, 0);
    vector<int> front(2, 0);

    for(int ind = n - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max(-arr[ind] + front[0], front[1]);
            }
            else
            {
                profit = max(arr[ind] - fee + front[1], front[0]);
            }
            cur[buy] = profit;
        }
        front = cur;
    }
    return cur[1];
}

int main()
{
    vector<int> arr = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    // int ans = rec_way(arr, 1, 0, fee);
    // int ans = memo_way(arr, fee); 
    // int ans = tabu_way(arr, fee);
    int ans = spaceOp_way(arr, fee);
    cout<<ans<<endl;
}