#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//Brute Force: Where we check sqrt of each number O(n)
// int square_root(int n)
// {
//     int ans = 0;
//     for(long long i = 0; i <= n;i++)
//     {
//         long long val = i * i;
//         if(val <= n * 1ll)
//         {
//             ans = i;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return ans;
// }

//Better: using built-in sqrt() function
// int square_root(int n)
// {
//     int ans = sqrt(n);
//     return ans;
// }

//Using Binary Search O(log n)
int square_root(int n)
{
    int low = 1, high = n;
    int ans = 0;
    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if(val <= (long long)(n))
        {
            ans = mid;
            low = mid + 1;
        }
        else if(val > n)
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int ans = square_root(n);
    cout<<ans<<endl;
}