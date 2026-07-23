// Using Memoization
// TC - O(n)
// SC - O(n) --> Recursion Stack space + O(n)

#include <iostream>
using namespace std;

int fib(int n)
{
    vector<int> dp(n+1, -1);
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}

int main()
{
    int n = 5;
    int a = fib(n);
    cout<<a<<endl;
}