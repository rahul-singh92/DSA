#include <iostream>
using namespace std;

const int mod = 1000000007;

int rec_way(string& a, int i, int j, int isTrue)
{
    if(i > j) return 0;

    if(i == j)
    {
        if(isTrue) return a[i] == 'T';
        else return a[i] == 'F';
    }

    long long ways = 0;

    for(int k = i + 1; k <= j - 1; k += 2)
    {
        long long lT = rec_way(a, i, k - 1, 1);
        long long lF = rec_way(a, i, k - 1, 0);
        long long rT = rec_way(a, k + 1, j, 1);
        long long rF = rec_way(a, k + 1, j, 0);

        if(a[k] == '&')
        {
            if(isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod; 
        }
        else if(a[k] == '|')
        {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else
        {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;
}

int solve_memoWay(string& a, vector<vector<vector<long long>>>& dp, int i, int j, int isTrue)
{
    if(i > j) return 0;

    if(i == j)
    {
        if(isTrue) return a[i] == 'T';
        else return a[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;

    for(int k = i + 1; k <= j - 1; k += 2)
    {
        long long lT = solve_memoWay(a, dp, i, k - 1, 1);
        long long lF = solve_memoWay(a, dp, i, k - 1, 0);
        long long rT = solve_memoWay(a, dp, k + 1, j, 1);
        long long rF = solve_memoWay(a, dp, k + 1, j, 0);

        if(a[k] == '&')
        {
            if(isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod; 
        }
        else if(a[k] == '|')
        {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else
        {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int memo_way(string& a)
{
    vector<vector<vector<long long>>> dp(a.size(), vector<vector<long long>>(a.size(), vector<long long>(2, -1)));

    return solve_memoWay(a, dp, 0, a.size() - 1, 1);
}

int tabu_way(string& a)
{
    vector<vector<vector<long long>>> dp(a.size(), vector<vector<long long>>(a.size(), vector<long long>(2, 0)));

    for(int i = a.size() - 1; i >= 0; i--)
    {
        for(int j = i; j <= a.size() - 1; j++)
        {
            for(int isTrue = 0; isTrue <= 1; isTrue++)
            {
                if(i == j)
                {
                    if(isTrue) dp[i][j][isTrue] = a[i] == 'T';
                    else dp[i][j][isTrue] = a[i] == 'F';
                    continue;
                }

                long long ways = 0;
                
                for(int k = i + 1; k <= j - 1; k += 2)
                {
                    long long lT = dp[i][k - 1][1];
                    long long lF = dp[i][k - 1][0];
                    long long rT = dp[k + 1][j][1];
                    long long rF = dp[k + 1][j][0];

                    if(a[k] == '&')
                    {
                        if(isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod; 
                    }
                    else if(a[k] == '|')
                    {
                        if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else
                    {
                        if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][a.size() - 1][1];
}

int main()
{
    string a = "F|T^F";

    // int ans = rec_way(a, 0, a.size() - 1, 1);
    // int ans = memo_way(a);
    int ans = tabu_way(a);
    cout<<ans<<endl;
}