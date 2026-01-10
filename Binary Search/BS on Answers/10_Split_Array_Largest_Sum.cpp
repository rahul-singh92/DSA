#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

// int wor_ca(vector<int> v, int n, int k)
// {
//     if(k > n) return -1;
//     int low = *max_element(v.begin(), v.end());
//     int high = accumulate(v.begin(), v.end(), 0);
//     for(int i = low; i <= high; i++)
//     {
//         int su = 1;
//         int su_sum = 0;
//         for(int j = 0; j < n; j++)
//         {
//             if(su_sum + v[j] <= i)
//             {
//                 su_sum += v[j];
//             }
//             else
//             {
//                 su_sum = v[j];
//                 su++;
//             }
//         }
//         if(su == k) return i;
//     }
//     return -1;
// }

int go_ca(vector<int> v, int n, int k)
{
    if(k > n) return -1;
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);
    while(low <= high)
    {
        int su = 1;
        int su_sum = 0;
        int mid = low + (high - low) / 2;
        for(int i = 0; i < n; i++)
        {
            if(su_sum + v[i] <= mid)
            {
                su_sum += v[i];
            }
            else
            {
                su_sum = v[i];
                su++;
            }
        }
        if(su <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0; i< n; i++)
    {
        cin>>v[i];
    }
    int ans = go_ca(v, n, k);
    cout<<ans<<endl;
}