#include <iostream>
using namespace std;

int rec_way(vector<int>& arr, int ind, int prev)
{
    if(ind == arr.size()) return 0;

    int length = 0;
    length = rec_way(arr, ind + 1, prev); // notTake
    if(prev == -1 || arr[ind] > arr[prev])
    {
        length = max(length, 1 + rec_way(arr, ind + 1, ind)); // take
    }
    return length;
}

int solve_memoWay(vector<int>& arr, vector<vector<int>>& dp, int ind, int prev)
{
    if(ind == arr.size()) return 0;

    if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
    int length = 0;

    length = solve_memoWay(arr, dp, ind + 1, prev);
    if(prev == -1 || arr[ind] > arr[prev])
    {
        length = max(length, 1 + solve_memoWay(arr, dp, ind + 1, ind));
    }
    return dp[ind][prev + 1] = length;
}

int memo_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size() + 1, -1));
    return solve_memoWay(arr, dp, 0, -1);
}

int tabu_way(vector<int>& arr)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, 0));

    for(int ind = arr.size() - 1; ind >= 0; ind--)
    {
        for(int prev = ind - 1; prev >= -1; prev--)
        {
            int length = 0;
            length = dp[ind+1][prev + 1];

            if(prev == -1 || arr[ind] > arr[prev])
            {
                length = max(length, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev + 1] = length;
        }
    }
    return dp[0][-1+1];
}

int spaceOp_way(vector<int>& arr)
{
    int n = arr.size();

    vector<int> next(n+1, 0), curr(n + 1, 0);

    for(int ind = n - 1; ind >= 0; ind--)
    {
        for(int prev = ind - 1; prev >= -1; prev--)
        {
            int length = 0;
            length = next[prev + 1];
            if(prev == -1 || arr[ind] > arr[prev])
            {
                length = max(length, 1 + next[ind+1]);
            }
            curr[prev + 1] = length;
        }
        next = curr;
    }
    return curr[-1 + 1];
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    // int ans = rec_way(arr, 0, -1);
    // int ans = memo_way(arr);
    // int ans = tabu_way(arr);
    int ans = spaceOp_way(arr);
    cout<<ans<<endl;
}