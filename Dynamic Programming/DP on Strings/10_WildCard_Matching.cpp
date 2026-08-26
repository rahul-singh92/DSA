#include <iostream>
using namespace std;

bool isAllStar(string& s, int ind)
{
    for(int i = 0; i <= ind; i++)
        if(s[i] != '*') return false;
    return true;
}

bool rec_way(string& s1, string& s2, int ind1, int ind2)
{
    if(ind1 < 0 && ind2 < 0) return true;

    if(ind1 < 0 && ind2 >= 0) return false;

    if(ind2 < 0 && ind1 >= 0) return isAllStar(s1, ind1);

    // match case
    if(s1[ind1] == s2[ind2] || s1[ind1] == '?') return rec_way(s1, s2, ind1 - 1, ind2 - 1); 

    // if *
    if(s1[ind1] == '*')
        return rec_way(s1, s2, ind1 - 1, ind2) || rec_way(s1, s2, ind1, ind2 - 1);
    return false;
}

bool solve_memoWay(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp)
{
    if(ind1 < 0 && ind2 < 0) return true;
    if(ind1 < 0 && ind2 >= 0) return false;

    if(ind1 >= 0 && ind2 < 0) return isAllStar(s1, ind1);

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2] || s1[ind1] == '?') return dp[ind1][ind2] =  solve_memoWay(s1, s2, ind1 - 1, ind2 - 1, dp); 

    if(s1[ind1] == '*') 
        return dp[ind1][ind2] = solve_memoWay(s1, s2, ind1 - 1, ind2, dp) || solve_memoWay(s1, s2, ind1, ind2 - 1, dp);
    return dp[ind1][ind2] = false;
}

bool memo_way(string& s1, string& s2)
{
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return solve_memoWay(s1, s2, s1.length() - 1, s2.length() - 1, dp);
}

bool isAllStarTabu(string& s1, int ind)
{
    for(int i = 1; i <= ind; i++)
        if(s1[i-1] != '*') return false;
    
    return true;
}

bool tabu_way(string& s1, string& s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));

    dp[0][0] = true;

    // empty pattern cant match non empty string
    for(int j = 1; j <= m; j++)
        dp[0][j] = false;

    // it can match only if *
    for(int i = 0; i <= n; i++)
        dp[i][0] = isAllStarTabu(s1, i);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j-1] || s1[i-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if(s1[i-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

bool spaceOp_way(string& s1, string& s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<int> prev(m+1, 0);
    vector<int> cur(m+1, 0);

    prev[0] = true;

    for(int i = 1; i <= n; i++)
    {
        cur[0] = isAllStarTabu(s1, i);
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?')
                cur[j] = prev[j-1];
            else if(s1[i-1] == '*')
                cur[j] = prev[j] || cur[j-1];
            else
                cur[j] = false;
        }
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string s1 = "*a*b";
    string s2 = "aaab";

    // bool ans = rec_way(s1, s2, s1.length(), s2.length());
    // bool ans = memo_way(s1, s2);
    // bool ans = tabu_way(s1, s2);
    bool ans = spaceOp_way(s1, s2);
    cout<<(ans == 1? "True": "False")<<endl;
}