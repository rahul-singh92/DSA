#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//Workst Case: Using Linear Search O(n * (max - min + 1))
// int min_da_to_make_m_bo(vector<int> vec, int n, int m, int k)
// {
//     int val = m * k;
//     if(val > n) return -1;
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     for(auto it: vec)
//     {
//         mini = min(mini, it);
//         maxi = max(maxi, it);
//     }
//     for(int i = mini; i <= maxi; i++)
//     {
//         int t = 0;
//         int b = 0;
//         for(int j = 0;j<n;j++)
//         {
//             if(i >= vec[j]) t++;
//             else
//             {
//                 b += (t / k);
//                 t = 0;
//             }
//         }
//         b += (t / k);
//         if(b >= m) return i;
//     }
//     return -1;
// }

int min_da_to_make_m_bo(vector<int> vec, int n, int m, int k)
{
    int val = m * k;
    if(val > n) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(auto it: vec)
    {
        mini = min(mini, it);
        maxi = max(maxi, it);
    }
    int low = mini, high = maxi;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int t = 0;
        int b = 0;
        for(int j = 0;j<n;j++)
        {
            if(mid >= vec[j])
            {
                t++;
            }
            else
            {
                b += (t/k);
                t = 0;
            }
        }
        b += (t/k);
        if(b >= m) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = min_da_to_make_m_bo(vec, n, m, k);
    cout<<ans<<endl;
}