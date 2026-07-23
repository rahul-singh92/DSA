#include <iostream>
using namespace std;

// using memoization
// int cs(vector<int>& dp,int n)
// {
//     if(n <= 1) return 1;
//     if(dp[n] != -1) return dp[n];

//     return dp[n] = cs(dp, n-1) + cs(dp, n - 2);
// }

// int main()
// {
//     int n = 3;
//     vector<int> dp(n+1, -1);
//     int a = cs(dp, n);
//     cout<<a<<endl;
// }


// using tabulation
// int main()
// {
//     int n = 3;
//     vector<int> dp(n+1, -1);

//     dp[0] = 1;
//     dp[1] = 1;

//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout<<dp[n]<<endl;
// }


// using space optimizaation tabulation
int main()
{
    int n = 3;

    int prev1 = 1, prev2 = 1;
    for(int i = 2; i <= n; i++)
    {
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    cout<<prev1<<endl;
}