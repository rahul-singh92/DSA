#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <math.h>
using namespace std;

//Worst case : O(max * n)
// int fin_sm_div(vector<int> vec, int n, int l)
// {
//     int maxi = INT_MIN;
//     for(auto it: vec)
//     {
//         maxi = max(maxi, it);
//     }
//     for(int i = 1;i<=maxi;i++)
//     {
//         int div = 0;
//         for(int j = 0;j<n;j++)
//         {
//             div += ceil((double)(vec[j]) / (double)(i));
//         }
//         if(div <= l) return i;
//     }
// }

int fin_sm_div(vector<int> vec, int n, int l)
{
    int maxi = INT_MIN;
    for(auto it: vec)
    {
        maxi = max(maxi, it);
    }
    int low = 1, high = maxi;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int div = 0;
        for(int j = 0;j<n;j++)
        {
            div += ceil((double)(vec[j]) / (double)(mid));
        }
        if(div <= l) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    int n, l;
    cin>>n>>l;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = fin_sm_div(vec, n, l);
    cout<<ans<<endl;
}