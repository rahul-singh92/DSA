#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <math.h>
using namespace std;

//Worst Case: O(max * n)
// int ko_ea_ba(vector<int> vec, int n, int h)
// {
//     int maxi = INT_MIN;
//     int count = 0;
//     for(auto it: vec)
//     {
//         maxi = max(maxi, it);
//     }
//     for(int i = 1;i<=maxi;i++)
//     {
//         int th = 0;
//         for(int j = 0;j<n;j++)
//         {
//             th += ceil((double)(vec[j])  / (double)(i));
//         }
//         if(th <= h) return i;
//     }
//     return maxi;
// }

//Using Binary Search O(n * log(max))
int ko_ea_ba(vector<int> vec, int n, int h)
{
    int maxi = INT_MIN;
    for(auto it:vec)
    {
        maxi = max(maxi, it);
    }
    int low = 0, high = maxi;
    while(low <= high)
    {
        int th = 0;
        int mid = low + (high - low) / 2;
        for(int i = 0;i<n;i++)
        {
            th += ceil((double)(vec[i]) / (double)(mid));
        }
        if(th <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n,h;
    cin>>n>>h;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = ko_ea_ba(vec,n,h);
    cout<<ans<<endl;
}