//Find all the subarrays whose res is equal to the given number
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute: Where we find xor of all elements and check with k O(n^2)
// int cou_sub(vector<int> vec, int n, int k)
// {
//     int count = 0;
//     for(int i = 0;i<n;i++)
//     {
//         int res = 0;
//         for(int j = i;j<n;j++)
//         {
//             res ^= vec[j];
//             if(res == k) count++;
//         }
//     }
//     return count;
// }

// we will store every xorr in hashMap and check if xorr ^ target is present in the hashMap.
int cou_sub(vector<int> vec, int n, int k)
{
    unordered_map<int, int> mpp;
    int xorr = 0;
    int count = 0;
    mpp[0]++;;
    for(int i = 0;i < n;i++)
    {
        xorr ^= vec[i];
        if(mpp.find(xorr ^ k) != mpp.end())
        {
            count += mpp[xorr ^ k];
            mpp[xorr]++;
        }
        else
        {
            mpp[xorr]++;
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
    int ans = cou_sub(vec,n,k);
    cout<<endl<<ans<<endl;
}