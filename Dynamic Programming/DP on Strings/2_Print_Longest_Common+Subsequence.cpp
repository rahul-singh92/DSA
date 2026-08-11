#include <iostream>
using namespace std;

string rec_way(string a, string b, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return "";

    if(a[ind1] == b[ind2]) return rec_way(a, b, ind1 - 1, ind2 - 1) + a[ind1];

    string x = rec_way(a, b, ind1 - 1, ind2);
    string y = rec_way(a, b, ind1, ind2 - 1);

    return (x.length() > y.length())? x:y;
}

int solve(string a, string b, vector<vector<int>>& dp, int ind1, int ind2)
{
    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(a[ind1] == b[ind2])
        return dp[ind1][ind2] = 1 + solve(a, b, dp, ind1 - 1, ind2 - 1);
    
    return dp[ind1][ind2] = max(solve(a, b, dp, ind1 - 1, ind2), solve(a, b, dp, ind1, ind2 - 1));
}

string memo_way(string a, string b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    int len = solve(a, b, dp, a.size() - 1, b.size() - 1);

    int index = len - 1;
    string ans = "";
    for(int i = 0; i < len; i++)
        ans += '$';
    
    int i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 && j >= 0)
    {
        if(a[i] == b[j])
        {
            ans[index] = a[i];
            index--;
            i--; j--;
        }
        else if(i == 0) j--;
        else if(j == 0) i--;
        else if(dp[i - 1][j] > dp[i][j-1])
            i = i - 1;
        else j = j - 1;
    }
    return ans;
}

string tabu_way(string a, string b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(int i = 0; i <= a.size(); i++) dp[i][0] = 0;
    for(int i = 0; i <= b.size(); i++) dp[0][i] = 0;
    
    for(int i = 1; i <= a.size();i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i - 1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[a.size()][b.size()];
    int index = len - 1;

    string ans = "";
    for(int i = 0; i < len; i++)    ans += '$';

    int i = a.size(), j = b.size();
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            ans[index] = a[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else j--;
    }
    return ans;
}

int main()
{
    string a = "abcd";
    string b = "bdef";

    // string ans = rec_way(a, b, a.size() - 1, b.size() - 1);
    // string ans = memo_way(a, b);
    string ans = tabu_way(a, b);
    cout<<ans<<endl;
}