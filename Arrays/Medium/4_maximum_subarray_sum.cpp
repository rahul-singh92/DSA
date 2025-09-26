#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Brute way O(n^3) almost
// int sub_sum(vector<int> vec, int n)
// {
//     int maxi = INT_MIN;
//     for(int i = 0;i < n;i++)
//     {
//         for(int j = i;j < n;j++)
//         {
//             int sum = 0;
//             for(int k = i;k <= j;k++)
//             {
//                 sum += vec[k];
//             }
//             maxi = max(sum,maxi); 
//         }
//     }
//     return maxi;
// }

//Better way by adding current ele witth previous subarray sum
// int sub_sum(vector<int> vec, int n)
// {
//     int maxi = INT_MIN;
//     for(int i = 0;i < n;i++)
//     {
//         int sum = 0;
//         for(int j = i;j < n;j++)
//         {
//             sum += vec[j];
//             maxi = max(sum,maxi); 
//         }
//     }
//     return maxi;
// }

//Best by seeing if sum !< 0 and if it is then resetting it to 0  O(n)
int sub_sum(vector<int> vec,int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        if(sum >= 0)
        {
            sum += vec[i];
            maxi = max(sum,maxi);
        }
        else sum = vec[i];
    }
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int a = sub_sum(vec,n);
    cout<<a<<endl;
}