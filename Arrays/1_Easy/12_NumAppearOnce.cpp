#include <iostream>
#include <vector>
#include <map>
using namespace std;
// int brute1(int arr[],int n)
// {
//     for(int i = 0;i<n;i++)
//     {
//         int count = 0;
//         int k = arr[i];
//         for(int j = 0;j<n;j++)
//         {
//             if(k == arr[j])
//             {
//                 count++;
//             }
//         }
//         if(count == 1) return arr[i];
//     }
//     return -1;
// }


// int opt1(int arr[],int n)
// {
//     int maxi = arr[0];
//     for(int i = 0;i<n;i++)
//     {
//         int maxi = max(maxi,arr[i]);
//     }

//     vector<int> hash(maxi+1,0);
//     for(int i = 0;i<n;i++)
//     {
//         hash[arr[i]]++;
//     }
//     for(int i = 0;i<n;i++)
//     {
//         if(hash[arr[i]] == 1)
//         {
//             return arr[i];
//         }
//     }
//     return -1;
// }

// int opt2(int arr[],int n)
// {
//     map<int,int> mpp;
//     for(int i = 0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it: mpp)
//     {
//         if(it.second == 1)
//         {
//             return it.first;
//         }
//     }
//     return -1;
// }

int best(int arr[],int n)
{
    int xorr = 0;
    for(int i = 0;i<n;i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a = best(arr,n);
    cout<<a;
}