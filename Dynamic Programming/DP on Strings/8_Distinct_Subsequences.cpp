#include <iostream>
using namespace std;

int rec_way(string& a, string& b, int ind1, int ind2)
{
    if(ind2 < 0) return 1;
    if(ind1 < 0) return 0;

    if(a[ind1] == b[ind2])  return rec_way(a, b, ind1 - 1, ind2 - 1) + rec_way(a, b, ind1 - 1, ind2);
    else return rec_way(a, b, ind1 - 1, ind2);
}

int solve_memoWay(string& a, string& b, vector<vector<int>>& dp, int ind1, int ind2)
{
    if(ind2 == b.size()) return 1;
    if(ind1 == a.size()) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(a[ind1] == b[ind2])  return dp[ind1][ind2] = solve_memoWay(a, b, dp, ind1+1, ind2+1) + solve_memoWay(a, b, dp, ind1+1, ind2);
    else return dp[ind1][ind2] = solve_memoWay(a, b, dp, ind1 + 1, ind2);
}

int memo_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    return solve_memoWay(a, b, dp, 0, 0);
}

int tabu_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(int i = 0; i <= b.size(); i++) dp[i][0] = 1;

    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[a.size()][b.size()];
}

int spaceOp_way(string& a, string& b)
{
    vector<int> prev(b.size() + 1, 0);
    prev[0] = 1;

    for(int i = 1; i <= a.size(); i++)
    {
        vector<int> curr = prev;
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1]) curr[j] = prev[j-1] + prev[j];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[b.size()];
}

int main()
{
    string a = "axbxax";
    string b = "axa";

    // int ans= rec_way(a, b, a.size() - 1, b.size() - 1);
    // int ans = memo_way(a, b);
    // int ans = tabu_way(a, b);
    int ans = spaceOp_way(a, b);
    cout<<ans<<endl;
}