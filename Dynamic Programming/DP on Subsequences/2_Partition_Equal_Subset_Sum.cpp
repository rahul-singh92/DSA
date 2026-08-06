#include <iostream>
using namespace std;

// Recursive Way
bool solve_recursive(int ind, int target, vector<int>& arr)
{
    // If the target sum is 0, we found a valid partition
    if(target == 0)
        return true;

    // If we have considered all elements and the target is still not 0, return false.
    if(ind == 0)
        return arr[0] == target;

    bool notTake = solve_recursive(ind - 1, target, arr);

    bool taken = false;
    if(arr[ind] <= target)
        taken = solve_recursive(ind - 1, target - arr[ind], arr);
    
    return notTake || taken;
}

bool recursive_way(vector<int>& arr)
{
    int totSum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }

    if(totSum % 2 == 1)
        return false;
    else 
    {
        int k = totSum / 2;

        return solve_recursive(arr.size() - 1, k, arr);
    }
}

// Memoization Way
bool solve_memoWay(int ind, int target, vector<int>& arr, vector<vector<int>>& dp)
{
    if(target == 0) return true;

    if(ind == 0) return arr[0] == target;

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTaken = solve_memoWay(ind - 1, target, arr, dp);

    bool taken = false;
    if(arr[ind] <= target)
        taken = solve_memoWay(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool memo_way(vector<int>& arr)
{
    int totSum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }

    if(totSum % 2 == 1)
        return false;
    else
    {
        vector<vector<int>> dp(arr.size(), vector<int>(totSum/2 + 1, -1));
        return solve_memoWay(arr.size() - 1, totSum/2, arr, dp);
    }
}

// tabulation way
bool solve_tabuWay(vector<int>& arr, int target)
{
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    // if target sum is 0
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // if first element is less than or equal to target
    if(arr[0] <= target)
        dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++)
    {
        for(int k = 1; k <= target; k++)
        {
            bool notTaken = dp[ind-1][k];

            bool taken = false;
            if(arr[ind] <= k)
                taken = dp[ind - 1][k - arr[ind]];
            
            dp[ind][k] = notTaken || taken;
        }
    }
    return dp[n-1][target];
}

bool tabulation_way(vector<int>& arr)
{
    int totSum = 0;
    for(auto x: arr)
        totSum += x;
    
    if(totSum % 2 == 1)
        return false;
    else 
    {
        int k = totSum / 2;
        return solve_tabuWay(arr, k);
    }
}

// bool spaceOp way
bool solve_spaceOpWay(vector<int>& arr, int target)
{
    int n = arr.size();
    
    vector<bool> prev(target + 1, false);

    prev[0] = true;
    if(arr[0] <= target)
        prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(target + 1, false);
        for(int k = 1; k <= target; k++)
        {
            bool notTaken = prev[k];

            bool taken = false;
            if(arr[ind] <= k)
                taken = prev[k-arr[ind]];
            curr[k] = notTaken || taken;
        }
        prev = curr;
    }
    return prev[target];
}

bool spaceOp_way(vector<int>& arr)
{
    int totSum = 0;
    for(auto x: arr)
        totSum += x;

    if(totSum % 2 == 1)
        return false;
    else
    {
        int k = totSum / 2;
        return solve_spaceOpWay(arr, k);
    }
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};

    // bool ans = recursive_way(arr);
    // bool ans = memo_way(arr);
    // bool ans = tabulation_way(arr);
    bool ans = spaceOp_way(arr);
    cout<<((ans == 1)? "True": "False")<<endl;
}