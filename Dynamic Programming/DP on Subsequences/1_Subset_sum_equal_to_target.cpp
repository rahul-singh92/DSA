#include <iostream>
using namespace std;

bool recursive_way(vector<int>& arr, int i, int target)
{
    if(target == 0) return true;
    if(i == 0) return (arr[0] == target);

    bool notTake = recursive_way(arr, i-1, target);

    bool take = false;
    if(target >= arr[i])
        take = recursive_way(arr, i-1, target - arr[i]);
    
    return take or notTake;
}

// Memoization Way
bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
{
    if(target == 0) return true;

    if(ind == 0) return arr[0] == target;

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTaken = solve(ind - 1, target, arr, dp);

    bool taken = false;
    if(target >= arr[ind])
        taken = solve(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = taken || notTaken;
}

bool memo_way(vector<int>& arr, int target)
{
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return solve(arr.size() - 1, target, arr, dp);
}

bool tabulation_way(vector<int>& arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // if target sum is 0 then we can always achieve it by taking no elements
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // if the first element of array is less than or equal to target, set dp[0][arr[0]] true
    if(arr[0] <= target)
    {
        dp[0][arr[0]] = true;
    }

    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 1; k <= target; k++)
        {
            bool notTaken = dp[ind-1][k];

            bool taken = false;
            if(arr[ind] <= k)
            {
                taken = dp[ind-1][k - arr[ind]];
            }

            dp[ind][k] = notTaken || taken;
        }
    }
    return dp[n-1][target];
} 

bool spaceOp_way(vector<int>& arr, int target)
{
    int n = arr.size();
    vector<bool> prev(target + 1, false);

    // sum 0 can always be formed by empty subset
    prev[0] = true;

    // If first element <= k, mark true
    if(arr[0] <= target)
    {
        prev[arr[0]] = true;
    }

    for(int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(target + 1, false);
        curr[0] = true;

        for(int k = 1; k <= target; k++)
        {
            bool notTaken = prev[k];
            bool taken = false;
            if(arr[ind] <= target)
            {
                taken = prev[k - arr[ind]];
            }
            curr[k] = notTaken || taken;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> arr = {4, 3, 5, 2};
    int k = 6;
    // bool ans = recursive_way(arr, arr.size() - 1, k);
    // bool ans = memo_way(arr, k);
    // bool ans = tabulation_way(arr, k);
    bool ans = spaceOp_way(arr, k);
    cout<<(ans == true? "True": "False")<<endl;
}