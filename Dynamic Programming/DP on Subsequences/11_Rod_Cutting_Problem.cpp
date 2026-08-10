#include <iostream>
using namespace std;

int rec_way(vector<int>& price, int N, int ind)
{
    if(ind < 0 || N == 0) return 0; // or if(ind == 0) return N * price[0]
    
    int notTake = rec_way(price, N, ind - 1);
    int take = 0;
    if(ind + 1 <= N)
        take = price[ind] + rec_way(price, N - (ind + 1), ind);
    return max(take, notTake);
}

// memoization way
int solve_memoWay(vector<int>& price, int N, vector<vector<int>>& dp, int ind)
{
    if(ind < 0 || N == 0) return 0;

    if(dp[ind][N] != -1) return dp[ind][N];

    int notTake = solve_memoWay(price, N, dp, ind - 1);
    int take = 0;
    if(ind + 1 <= N)
        take = price[ind] + solve_memoWay(price, N - (ind + 1), dp, ind);
    return dp[ind][N] = max(take, notTake);
}

int memo_way(vector<int>& price, int N)
{
    vector<vector<int>> dp(price.size(), vector<int>(N + 1, -1));
    return solve_memoWay(price, N, dp, price.size() - 1);
}

int tabu_way(vector<int>& price, int N)
{
    vector<vector<int>> dp(price.size(), vector<int>(N + 1, 0));

    for(int i = 0; i <= N; i++)
        dp[0][i] = price[0] * i;
    
    for(int ind = 1; ind < price.size(); ind++)
    {
        for(int k = 0; k <= N; k++)
        {
            int notTake = dp[ind - 1][k];
            int take = 0;
            if(ind + 1 <= k)
                take = price[ind] + dp[ind][k - (ind + 1)];
            dp[ind][k] = max(take, notTake);
        }
    }
    return dp[price.size() - 1][N];
}

int spaceOp_way(vector<int>& price, int N)
{
    vector<int> prev(N + 1, 0);

    for(int i = 0; i <= N; i++) prev[i] = price[0] * i;

    for(int ind = 1; ind < price.size(); ind++)
    {
        vector<int> curr(N + 1, 0);
        for(int k = 0; k <= N; k++)
        {
            int notTake = prev[k];
            int take = 0;
            if(ind + 1 <= k)
                take = price[ind] + curr[k - (ind + 1)];
            curr[k] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[N];
}

int main()
{
    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int N = 8;

    // int ans = rec_way(price, N, price.size() - 1);
    // int ans = memo_way(price, N);
    // int ans = tabu_way(price, N);   
    int ans = spaceOp_way(price, N);
    cout<<ans<<endl;
}