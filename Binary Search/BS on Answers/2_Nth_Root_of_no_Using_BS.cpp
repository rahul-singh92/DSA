#include <iostream>
using namespace std;

//Brute : Becasue we take whole linear search and also for func(log n) so O(m * log n)
// long long func(int i, int n)
// {
//     long long ans = 1;
//     long long base = i;
//     while(n > 0)
//     {
//         if(n % 2)
//         {
//             n--;
//             ans = ans * base;
//         }
//         else
//         {
//             n /= 2;
//             base = base * base;
//         }
//     }
//     return ans;
// }
// int nthRoot(int n, int m)
// {
//     for(int i = 1;i <= m; i++)
//     {
//         long long val = func(i, n);
//         if(val == m * 1ll) return i;
//         else if(val > m * 1ll) break;
//     }
//     return -1;
// }

//Better using BS: O(log2m * log2n) 
int func(int mid, int n, int m)
{
    long long ans = 1;
    for(int i = 1;i<=n;i++)
    {
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int nthRoot(int n, int m)
{
    int low = 1, high = m;
    while(low <= high)
    {
        int mid = low + (high - low ) / 2;
        int midN = func(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int ans = nthRoot(n,m);
    cout<<ans<<endl;
}