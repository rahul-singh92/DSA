// Find the longest subarray with all elements sum to 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute force: worst beacuse we are using 3 loops which can outcome to O(n^3)
// int lar_sub(vector<int> vec, int n)
// {
//     int max_count = 0;
//     for(int i = 0;i<n;i++)
//     {
//         int sum = 0;
//         for(int j = i;j<n;j++)
//         {
//             int count = 0;
//             sum += vec[j];
//             if(sum == 0)
//             {
//                 vector<int> t;
//                 for(int k = i; k<=j;k++)
//                 {
//                     count++;
//                 }
//                 max_count = max(count, max_count);
//             }
//         }
//     }
//     return max_count;
// }

//Better way is by reducing it to 2 loop O(n^2)
// int lar_sub(vector<int> vec, int n)
// {
//     int max_count = 0;
//     for(int i = 0;i<n;i++)
//     {
//         int sum = 0;
//         int count = 0;
//         for(int j = i;j<n;j++)
//         {
//             count++;
//             sum += vec[j];
//             if(sum == 0)
//             {
//                 max_count = max(count, max_count);
//             }
//         }
//     }
//     return max_count;
// }

//Now it can be reduced to O(n) by using hash map. We will find sum of each ele in arr and then see if previously the sum
// existed, if yes that means the other sum must be 0 so we will count it.
int lar_sub(vector<int> vec, int n)
{
    unordered_map<int, int> mpp;
    int max_count = 0;
    int sum = 0;
    for(int i = 0; i < n;i++)
    {
        sum += vec[i];
        if(sum == 0) 
        {
            max_count = i+1;
        }
        else
        {
            if(mpp.find(sum) != mpp.end())
            {
                max_count = max(max_count, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return max_count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = lar_sub(vec,n);
    cout<<endl<<ans<<endl;
}