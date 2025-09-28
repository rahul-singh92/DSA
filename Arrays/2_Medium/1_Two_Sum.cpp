#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//Brute force approach
// bool two_sum(int arr[],int n,int target)
// {
//     for(int i = 0; i<n;i++)
//     {
//         for(int j = i+1;j<n;j++)
//         {
//             if(arr[i] + arr[j] == target)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//using map
bool two_sum(int arr[],int n,int target)
{
    map<int, int> mpp;
    for(int i = 0;i<n;i++)
    {
        int a = arr[i];
        int re_t = target - a;
        if(mpp.find(re_t) != mpp.end())
        {
            return true;
        }
        mpp[a] = i;
    }
    return false;
}

// Better approach (two pointer approach) without map
// bool two_sum(int arr[],int n,int target)
// {
//     sort(arr,arr+n);
//     int i = 0, j = n-1;
//     while(i < j)
//     {
//         if(arr[i] + arr[j] == target) return true;
//         if(arr[i] + arr[j] < target) i++;
//         else if(arr[i] + arr[j] > target) j--;
//     }
//     return false;
// }

int main()
{
    int n,target;
    cin>>n>>target;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool a = two_sum(arr,n,target);
    cout<<a<<endl;
}