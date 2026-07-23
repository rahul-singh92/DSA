// Using tabulation
// TC - O(n);
// SC - O(n) --> no stack space like recursion so better answer

// #include <iostream>
// using namespace std;

// int fib(vector<int> &dp, int n)
// {
//     for(int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
//     return dp[n];
// }

// int main()
// {
//     int n = 5;
//     vector<int> dp(n+1);
//     dp[0] = 0, dp[1] = 1;
//     int a = fib(dp, n);
//     cout<<a<<endl;
// }


// Better way to reduce more spce
// SC - O(1), Tc - O(n)
#include <iostream>
using namespace std;

int fib(int& prev1, int& prev2, int n)
{
    int curi;
    for(int i = 2; i <= n; i++)
    {
        curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return curi;;
}

int main()
{
    int n = 5;
    int prev1 = 1, prev2 = 0;
    int a = fib(prev1, prev2, n);
    cout<<a<<endl;
}
