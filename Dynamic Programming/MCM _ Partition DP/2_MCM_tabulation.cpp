#include <iostream>
using namespace std;

int tabu_way(vector<int>& arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 1; i < n; i++)
        dp[i][i] = 0;

    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            int mini = INT_MAX;
            for(int k = i; k < j; k++)
            {
                int count1 = dp[i][k];
                int count2 = dp[k+1][j];
                int costMul = arr[i - 1] * arr[k] * arr[j];

                int tot = count1 + count2 + costMul;
                mini = min(mini, tot);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int main()
{
    vector<int> arr = {10, 15, 20, 25};

    int ans = tabu_way(arr);
    cout<<ans<<endl;
}