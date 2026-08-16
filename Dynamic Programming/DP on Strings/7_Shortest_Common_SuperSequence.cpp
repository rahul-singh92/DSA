#include <iostream>
using namespace std;

int solve_memo_way(string& a, string& b, vector<vector<int>>& dp, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(a[ind1] == b[ind2]) return dp[ind1][ind2] = 1 + solve_memo_way(a, b, dp, ind1 - 1, ind2 - 1);

    return dp[ind1][ind2] =  max(solve_memo_way(a, b, dp, ind1-1, ind2), solve_memo_way(a, b, dp, ind1, ind2-1));
}

string memo_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    int lcs = solve_memo_way(a, b, dp, a.size() - 1, b.size() - 1);
    cout<<a.size() + b.size() - lcs<<endl;

    int i = a.size() - 1;
    int j = b.size() - 1;
    string ans = "";

    while(i >= 0 && j >= 0)
    {
        if(a[i] == b[j])
        {
            ans += a[i];
            i--;
            j--;
        }
        else if(i == 0)
        {
            ans += b[j];
            j--;
        }
        else if(j == 0)
        {
            ans += a[i];
            i--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans += a[i];
            i--;
        }
        else
        {
            ans += b[j];
            j--;
        }
    }

    while(i >= 0)
    {
        ans += a[i];
        i--;
    }

    while(j >= 0)
    {
        ans += b[j];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string tabu_way(string& a, string& b)
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

    cout<<a.size() + b.size() - dp[a.size()][b.size()]<<endl;

    int i = a.size();
    int j = b.size();
    string ans = "";

    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            ans += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans += a[i-1];
            i--;
        }
        else
        {
            ans += b[j-1];
            j--;
        }
    }

    while(i > 0)
    {
        ans += a[i-1];
        i--;
    }

    while(j > 0)
    {
        ans += b[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "mno";
    string b = "nop";

    // string ans = memo_way(a, b);
    string ans = tabu_way(a, b);
    cout<<ans<<endl;
}