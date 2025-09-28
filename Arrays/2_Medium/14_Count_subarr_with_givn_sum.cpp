#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute: where we check all the sum of the arrays
// int count_sub(vector<int> vec, int n, int k)
// {
//     int count = 0;
//     for(int i = 0;i<n;i++)
//     {
//         int sum = 0;
//         for(int j = i; j <= n;j++)
//         {
//             sum += vec[j];
//             if(sum == k)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

//Rather than finding all arr, we will store the pre_sum in map and its count then we will find pre_sum - k(given sum) and check if it exists
int count_sub(vector<int> vec, int n, int k)
{
    unordered_map<int,int> mpp(0);
    int count = 0;
    int pre_sum = 0;
    mpp[pre_sum]++;
    for(int i = 0;i<n;i++)
    {
        pre_sum += vec[i];
        if(mpp.find(pre_sum - k) != mpp.end())
        {
            count += mpp[pre_sum - k];
            mpp[pre_sum]++;
        }
        else
        {
            mpp[pre_sum]++;
        }
    }
    return count;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = count_sub(vec,n,k);
    cout<<ans<<endl;
}