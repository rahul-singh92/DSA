#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// int wo_ca(vector<int> v, int n, int k)
// {
//     if(k > n) return -1;
//     int low = *max_element(v.begin(), v.end());
//     int high = accumulate(v.begin(), v.end(), 0);
//     for(int i = low; i <= high; i++)
//     {
//         int boards = 1;
//         int boards_sum = 0;
//         for(int j = 0; j < n; j++)
//         {
//             if(boards_sum + v[j] <= i)
//             {
//                 boards_sum += v[j];
//             }
//             else
//             {
//                 boards_sum = v[j];
//                 boards++;
//             }
//         }
//         if(boards == k) return i;
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
        int mid = low + (high - low) / 2;
        int boards = 1;
        int boards_sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(boards_sum + v[j] <= mid)
            {
                boards_sum += v[j];
            }
            else
            {
                boards_sum = v[j];
                boards++;
            }
        }
        if(boards <= k) high = mid -1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int ans = go_ca(v, n, k);
    cout<<ans<<endl;
}