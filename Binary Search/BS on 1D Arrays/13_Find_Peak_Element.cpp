#include <iostream>
#include <vector>
using namespace std;

//Brute Force where we check every element O(n)
// vector<int> peak_ele(vector<int> vec, int n)
// {
//     vector<int> ans;
//     if(n == 0)
//     {
//         ans.push_back(0);
//         return ans;
//     }
//     if(vec[0] > vec[1])
//     {
//         ans.push_back(0);
//     }
//     if(vec[n-1] > vec[n-2])
//     {
//         ans.push_back(n-1);
//     }
//     for(int i = 1;i<n-1;i++)
//     {
//         if(vec[i] > vec[i-1] && vec[i] > vec[i+1])
//         {
//             ans.push_back(i);
//         }
//     }
//     return ans;
// }

int peak_ele(vector<int> vec, int n)
{
    if(n == 1 || vec[0] > vec[1]) return 0;
    if(vec[n-1] > vec[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; //Overflow
        if(vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1]) return mid;
        if(vec[mid] > vec[mid - 1]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    // vector<int> ans = peak_ele(vec, n);
    // for(auto it: ans)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    int ans = peak_ele(vec, n);
    cout<<ans<<endl;
}