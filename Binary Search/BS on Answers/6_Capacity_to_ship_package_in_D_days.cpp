#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//Brute Force O(n* (sum - maxi + 1))
// int cap_to_shi(vector<int> vec, int n, int d)
// {
//     int maxi = INT_MIN;
//     int sum = 0;
//     for(auto it: vec)
//     {
//         maxi = max(maxi, it);
//         sum += it;
//     }
//     for(int i = maxi; i<= sum;i++)
//     {
//         int c_d = 1;
//         int load = 0;
//         for(int j = 0;j<n;j++)
//         {
//             if(load + vec[j] > i)
//             {
//                 c_d++;
//                 load = vec[j];
//             }
//             else
//             {
//                 load += vec[j];
//             }
//         }
//         if(c_d <= d) return i;
//     }
//     return -1;
// }

int cap_to_shi(vector<int> vec, int n, int d)
{
    int maxi = INT_MIN;
    int sum = 0;
    for(auto it: vec)
    {
        maxi = max(maxi, it);
        sum += it;
    }
    int low = maxi, high = sum;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int c_d = 1;
        int load = 0;
        for(int j = 0;j<n;j++)
        {
            if(load + vec[j] > mid)
            {
                c_d++;
                load = vec[j];
            }
            else 
            {
                load += vec[j];
            }
        }
        if(c_d > d)
        {
            low  = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
}

int main()
{
    int n, d;
    cin>>n>>d;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = cap_to_shi(vec, n, d);
    cout<<ans<<endl;
}