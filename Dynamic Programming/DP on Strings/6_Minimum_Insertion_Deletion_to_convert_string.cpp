#include <iostream>
using namespace std;

int rec_way(string& a, string& b, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(a[ind1] == b[ind2]) return 1 + rec_way(a, b, ind1 - 1, ind2 - 1);

    return max(rec_way(a, b, ind1 - 1, ind2), rec_way(a, b, ind1, ind2 - 1));
}

int solve_memoWay(string& a, string& b, vector<vector<int>>& dp, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(a[ind1] == b[ind2]) return dp[ind1][ind2] = 1 + solve_memoWay(a, b, dp, ind1 - 1, ind2 - 1);

    return dp[ind1][ind2] = max(solve_memoWay(a, b, dp, ind1 - 1, ind2), solve_memoWay(a, b, dp, ind1, ind2 - 1));
}

int memo_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    return solve_memoWay(a, b, dp, a.size() - 1, b.size() - 1);
}

int tabu_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a.size()][b.size()];
}

int spaceOp_way(string& a, string& b)
{
    vector<int> prev(b.size() + 1, 0);

    for(int i = 1; i <= a.size(); i++)
    {
        vector<int> curr(b.size() + 1, 0);
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[b.size()];
}

int main()
{
    string a = "kitten";
    string b = "sitting";

    // int lcs = rec_way(a, b, a.size() - 1, b.size() - 1);
    // int lcs = memo_way(a, b);
    // int lcs = tabu_way(a, b);
    int lcs = spaceOp_way(a, b);
    int ans = a.size() - lcs + b.size() - lcs;

    cout<<ans<<endl;
}