#include <iostream>
using namespace std;

// Recursive way
int solve_recWay(int sInd, int cInd, vector<int>& student, vector<int>& cookie)
{
    if(sInd >= student.size() || cInd >= cookie.size())
        return 0;
    
    int result = 0;

    if(cookie[cInd] >= student[sInd])
        result = max(result, 1 + solve_recWay(sInd + 1, cInd + 1, student, cookie)); // take it
    
    // not take and try the next one
    result = max(result, solve_recWay(sInd, cInd + 1, student, cookie));

    return result;
}

int recursive_way(vector<int>& student, vector<int>& cookie)
{
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    return solve_recWay(0, 0, student, cookie);
}

// Memoization way
int solve_memoWay(int sInd, int cInd, vector<int>& student, vector<int>& cookie, vector<vector<int>>& dp)
{
    if(sInd >= student.size() || cInd >= cookie.size())
        return 0;

    if(dp[sInd][cInd] != -1) return dp[sInd][cInd];

    int result = 0;
    if(cookie[cInd] >= student[sInd])
        return result = max(result, 1 + solve_memoWay(sInd + 1, cInd + 1, student, cookie, dp));
    
    result = max(result, solve_memoWay(sInd, cInd + 1, student, cookie, dp));

    return dp[sInd][cInd] = result;
}

int memo_way(vector<int>& student, vector<int>& cookie)
{
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    vector<vector<int>> dp(student.size(), vector<int>(cookie.size(), -1));
    return solve_memoWay(0, 0, student, cookie, dp);
}

//Tabulation way
int tabu_way(vector<int>& student, vector<int>& cookie)
{
    int n = student.size();
    int m = cookie.size();

    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            int skip = dp[i][j + 1];

            int take = 0;
            if(cookie[j] >= student[i])
                take = 1 + dp[i+1][j+1];

            dp[i][j] = max(skip, take);
        }
    }
    return dp[0][0];
}

// Optimial way
int opt_way(vector<int>& student, vector<int>& cookie)
{
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    int sInd = 0, cInd = 0;

    while(sInd < student.size() && cInd < cookie.size())
    {
        if(cookie[cInd] >= student[sInd])
        {
            sInd++;
        }
        cInd++;
    }
    return sInd;
}

int main()
{
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    // int ans = recursive_way(student, cookie);
    // int ans = memo_way(student, cookie);
    // int ans = tabu_way(student, cookie);
    int ans = opt_way(student, cookie);
    cout<<ans<<endl;
}