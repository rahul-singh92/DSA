// Using Memoization
// TC - O(n)
// SC - O(n) --> Recursion Stack space + O(n)

#include <iostream>
using namespace std;

int fib(int n, vector<int>& dp)
{
    if(n <= 1) return n;
    
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main()
{
    int n = 5;
    vector<int> dp(n+1, -1);
    int a = fib(n,dp);
    cout<<a<<endl;
}