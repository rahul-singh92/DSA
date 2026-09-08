#include <iostream>
using namespace std;

bool isPalindrome(string a, int i, int j)
{
    while(i <= j)
    {
        if(a[i] != a[j]) return false;
        i++;
        j--;
    }
    return true;
}

int rec_way1(string& s, int i)
{
    // if(i == s.size() || isPalindrome(s, i, s.size() - 1)) return 0;
    if(i == s.size()) return 0; // if not minus 0 in end because it cuts the last index after end of the array as 1 palindrome;

    int minCost = INT_MAX;

    // i....j
    for(int j = i; j < s.size(); j++)
    {
        if(isPalindrome(s, i, j)) 
        {
            int cost = 1 + rec_way1(s, j + 1);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

int rec_way2(string& s, int i)
{
    if(i == s.size() || isPalindrome(s, i, s.size() - 1)) return 0;

    int minCost = INT_MAX;

    for(int j = i; j < s.size(); j++)
    {
        if(isPalindrome(s, i, j))
        {
            int cost = 1 + rec_way2(s, j + 1);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}


int solve_memoWay(string& a, vector<int>& dp, int i)
{
    if(i == a.size() || isPalindrome(a, i, a.size() - 1)) return 0;

    if(dp[i] != -1) return dp[i];

    int minCut = INT_MAX;

    for(int j = i; j < a.size(); j++)
    {
        if(isPalindrome(a, i, j))
        {
            int cut = 1 + solve_memoWay(a, dp, j + 1);
            minCut = min(minCut, cut);
        }
    }
    return dp[i] = minCut;
}

int memo_way(string& a)
{
    vector<int> dp(a.size(), -1);
    return solve_memoWay(a, dp, 0);
}

int tabu_way(string& a)
{
    vector<int> dp(a.size() + 1, 0);

    for(int i = a.size() - 1; i >= 0; i--)
    {
        int minCut = INT_MAX;
        if(isPalindrome(a, i, a.size() - 1))
        {
            dp[i] = 0;
            continue;
        }
        for(int j = i; j < a.size(); j++)
        {
            if(isPalindrome(a, i, j))
            {
                int cut = 1 + dp[j + 1];
                minCut = min(minCut, cut);
            }
        }
        dp[i] = minCut;
    }
    return dp[0];
}

int main()
{
    string s = "bababcbadcede";

    // int ans = rec_way1(s, 0) - 1; // beacuse it do partition at the end
    // int ans = rec_way2(s, 0);
    // int ans = memo_way(s);
    int ans = tabu_way(s);
    cout<<ans<<endl;
}