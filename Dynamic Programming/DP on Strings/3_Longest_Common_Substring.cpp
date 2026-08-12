#include <iostream>
using namespace std;

int rec_way(string& a, string& b, int ind1, int ind2, int count)
{
    if(ind1 < 0 || ind2 < 0) return count;

    int current = count;

    if(a[ind1] == b[ind2])
        current = rec_way(a, b, ind1 - 1, ind2 - 1, count + 1);
    
    int o1 = rec_way(a, b, ind1 - 1, ind2, 0);
    int o2 = rec_way(a, b, ind1, ind2 - 1, 0);

    return max({current, o1, o2});
}

int solve_memoWay(string& a, string& b, int ind1, int ind2, vector<vector<vector<int>>>& dp,int count)
{
    if(ind1 < 0 || ind2 < 0)
        return count;
    
    if(dp[ind1][ind2][count] != -1) return dp[ind1][ind2][count];

    int current = count;

    if(a[ind1] == b[ind2])  current = solve_memoWay(a, b, ind1 - 1, ind2 - 1, dp, count + 1);

    int o1 = solve_memoWay(a, b, ind1 - 1, ind2, dp, 0);
    int o2 = solve_memoWay(a, b, ind1, ind2 - 1, dp, 0);

    return dp[ind1][ind2][count] =  max({current, o1, o2});
}

int memo_way(string& a, string& b)
{
    vector<vector<vector<int>>> dp(a.size(), vector<vector<int>>(b.size(), vector<int>(min(a.size(), b.size()) + 1, -1)));
    return solve_memoWay(a, b, a.size() - 1, b.size() - 1, dp, 0);
}

int tabu_way(string& a, string& b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    int ans = 0;
    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else 
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int spaceOp_way(string& a, string& b)
{
    vector<int> prev(a.size() + 1, 0);

    int ans = 0;
    for(int i = 1; i <= a.size(); i++)
    {
        vector<int> curr(b.size() + 1, 0);
        for(int j = 1; j <= b.size(); j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}

int main()
{
    string a = "abcde";
    string b = "abfce"; 

    // int ans = rec_way(a, b, a.size() - 1, b.size() - 1, 0);
    // int ans = memo_way(a, b);
    // int ans = tabu_way(a, b);
    int ans = spaceOp_way(a, b);
    cout<<ans<<endl;
}