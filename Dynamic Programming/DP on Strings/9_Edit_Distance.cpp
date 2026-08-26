#include <iostream>
using namespace std;

// My thinking
// int rec_way(string &s1, string &s2, int ind1, int ind2)
// {
//     if(ind1 < 0 || ind2 < 0) return 0;

//     if(s1[ind1] == s2[ind2]) return 1 + rec_way(s1, s2, ind1 - 1, ind2 - 1);

//     return max(rec_way(s1, s2, ind1 - 1, ind2), rec_way(s1, s2, ind1, ind2 - 1));
// }

// int r_way(string &s1, string &s2)
// {
//     int same = rec_way(s1, s2, s1.length() - 1, s2.length() - 1); //4

//     int ans = max(s1.length(), s2.length()) - min(s1.length(), s2.length()); // 2

//     ans += abs((int)min(s1.length(), s2.length()) - same); // 6 - 4
//     return ans;
// }

int rec_way(string &s1, string& s2, int ind1, int ind2)
{
    if(ind1 < 0) return ind2 + 1;
    if(ind2 < 0) return ind1 + 1;

    if(s1[ind1] == s2[ind2]) return rec_way(s1, s2, ind1 - 1, ind2 - 1);

    return 1 + min({rec_way(s1, s2, ind1, ind2 - 1), rec_way(s1, s2, ind1 - 1, ind2), rec_way(s1, s2, ind1 - 1, ind2 - 1)});
}

int solve_memoWay(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp)
{
    if(ind1 < 0) return ind2 + 1;
    if(ind2 < 0) return ind1 + 1;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = solve_memoWay(s1, s2, ind1 - 1,ind2 - 1, dp);
    else return dp[ind1][ind2] = 1 + min({
        solve_memoWay(s1, s2, ind1, ind2 - 1, dp),
        solve_memoWay(s1, s2, ind1 - 1, ind2, dp),
        solve_memoWay(s1, s2, ind1 - 1, ind2 - 1, dp)
    });
}

int memo_way(string& s1, string& s2)
{
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return solve_memoWay(s1, s2, s1.length() - 1, s2.length() - 1, dp);
}

int tabu_way(string& s1, string& s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}

int spaceOp_way(string& s1, string& s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<int> prev(m + 1, 0);
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++)
    {
        vector<int> cur(m + 1, 0);
        cur[0] = i;
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) cur[j] = prev[j - 1];
            else cur[j] = 1 + min({prev[j], cur[j-1], prev[j-1]});
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1 = "a";
    string s2 = "b";

    // int ans = r_way(s1, s2);
    // int ans = rec_way(s1, s2, s1.length() - 1, s2.length() - 1);
    // int ans = memo_way(s1, s2);
    // int ans = tabu_way(s1, s2);
    int ans = spaceOp_way(s1, s2);
    cout<<ans<<endl;
}