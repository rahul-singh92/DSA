#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int buy, int ind, int capacity)
{
    if(ind == arr.size() || capacity == 0) return 0;

    int profit = 0;
    if(buy)
    {
        profit = max(-arr[ind] + rec_way(arr, 0, ind + 1, capacity), rec_way(arr, 1, ind + 1, capacity));
    }
    else
    {
        profit = max(arr[ind] + rec_way(arr, 1, ind + 1, capacity - 1), rec_way(arr, 0, ind + 1, capacity));
    }   
    return profit;
}

int solve_memoWay(vector<int>& arr, vector<vector<vector<int>>>& dp, int buy, int ind, int cap)
{
    if(ind == arr.size() || cap == 0) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit;

    if(buy)
    {
        profit = max(-arr[ind] + solve_memoWay(arr, dp, 0, ind + 1, cap), solve_memoWay(arr, dp, 1, ind + 1, cap));
    }
    else
    {
        profit = max(arr[ind] + solve_memoWay(arr, dp, 1, ind + 1, cap - 1), solve_memoWay(arr, dp, 0,ind + 1, cap));
    }
    return dp[ind][buy][cap] = profit;
}

int memo_way(vector<int>& arr, int cap)
{
    vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(2, vector<int>(cap + 1, -1)));
    return solve_memoWay(arr, dp, 1, 0, cap);
}

int tabu_way(vector<int>& arr, int cap)
{
    vector<vector<vector<int>>> dp(arr.size() + 1, vector<vector<int>>(2, vector<int>(cap + 1, 0)));

    int profit = 0;
    for(int ind = arr.size() - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy<= 1; buy++)
        {
            for(int capacity = 1; capacity <= cap; capacity++)
            {
                if(buy)
                {
                    profit = max(-arr[ind] + dp[ind + 1][0][capacity], dp[ind+1][1][capacity]);
                }
                else 
                {
                    profit = max(arr[ind] + dp[ind+1][1][capacity - 1], dp[ind+1][0][capacity]);
                }

                dp[ind][buy][capacity] = profit;
            }
        }
    }
    return dp[0][1][cap];
}

int spaceOp_way(vector<int>& arr, int cap)
{
    vector<vector<int>> ahead(2, vector<int>(cap+1, 0));
    vector<vector<int>> cur(2, vector<int>(cap+1, 0));

    int profit = 0;
    for(int ind = arr.size() - 1; ind >= 0; ind--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int capacity = 1; capacity <= cap; capacity++)
            {
                if(buy)
                {
                    profit = max(-arr[ind] + ahead[0][capacity], ahead[1][capacity]);
                }
                else
                {
                    profit = max(arr[ind] + ahead[1][capacity - 1], ahead[0][capacity]);
                }
                cur[buy][capacity] = profit;
            }
        }
        ahead = cur;
    }
    return ahead[1][cap];
}

int main()
{
    vector<int> arr = {3, 3, 5, 0, 0, 1, 4};
    int cap = 2;

    // int ans = rec_way(arr, 1, 0, cap);
    // int ans = memo_way(arr, cap);
    // int ans = tabu_way(arr, cap);
    int ans = spaceOp_way(arr, cap);
    cout<<ans<<endl;
}