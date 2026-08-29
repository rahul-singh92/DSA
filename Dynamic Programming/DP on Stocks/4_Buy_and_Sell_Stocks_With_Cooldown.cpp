#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int buy, int ind)
{
    if(ind >= arr.size()) return 0;

    int price = 0;
    if(buy)
    {
        price = max(-arr[ind] + rec_way(arr, 0, ind + 1), rec_way(arr, 1, ind + 1));
    }
    else
    {
        price = max(arr[ind] + rec_way(arr, 1, ind + 2), rec_way(arr, 0, ind + 1));
    }
    return price;
}

int solve_memoWay(vector<int>& arr, vector<vector<int>>& dp, int buy, int ind)
{
    if(ind >= arr.size()) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int price = 0;
    if(buy)
    {
        price = max(-arr[ind] + solve_memoWay(arr, dp, 0, ind + 1), solve_memoWay(arr, dp, 1, ind + 1));
    }
    else 
    {
        price = max(arr[ind] + solve_memoWay(arr, dp, 1, ind + 2), solve_memoWay(arr, dp, 0, ind + 1));
    }
    return dp[ind][buy] = price;
}

int memo_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(2, -1));
    return solve_memoWay(arr, dp, 1, 0);
}

int tabu_way(vector<int>& arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            int price;

            if(buy)
            {
                price = max(-arr[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else
            {
                price = max(arr[ind] + dp[ind + 2][1], dp[ind + 1][0]);
            }
            dp[ind][buy] = price;
        }
    }
    return dp[0][1];
}

int spaceOp_way(vector<int>& arr)
{
    int n = arr.size();
    vector<int> curr(2, 0);
    vector<int> front1(2, 0);
    vector<int> front2(2, 0); // max profit 2 step ahead
    
    for(int ind = n - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                profit = max(-arr[ind] + front1[0], front1[1]);
            }
            else
            {
                profit = max(arr[ind] + front2[1], front1[0]);
            }
            curr[buy] = profit;
        }
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}

int main()
{
    vector<int> arr = {4,9, 0, 4, 10};

    // int ans = rec_way(arr, 1, 0);
    // int ans = memo_way(arr);
    // int ans = tabu_way(arr);
    int ans = spaceOp_way(arr);
    cout<<ans<<endl;
}