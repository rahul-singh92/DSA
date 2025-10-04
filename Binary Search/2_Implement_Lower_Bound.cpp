#include <iostream>
#include <vector>
using namespace std;

//Brute: Linear search in all the elements O(n)
// int imp_low_bou(vector<int> vec, int n, int x)
// {
//     int index = -1;
//     for(int i = 0;i<n;i++)
//     {
//         if(vec[i] >= x)
//         {
//             index = i;
//             break;
//         }
//     }
//     return index;
// }

//Binary Search using loop
// int imp_low_bou(vector<int> vec, int n, int x)
// {
//     int low = 0;
//     int high = n-1;
//     int ans = n;
//     while(low <= high)
//     {
//         int mid = (low + high) / 2;
//         if(vec[mid] >= x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

//Using Recursion
int imp_low_bou(vector<int> vec, int low, int high, int x)
{
    int ans = vec.size();
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(vec[mid] >= x)
    {
        ans = mid;
        imp_low_bou(vec, low, mid-1, x);
    }    
    else return imp_low_bou(vec, mid+1, high, x);
    return ans;
}

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    // int ans = imp_low_bou(vec, n, x);   For loop 
    int ans = imp_low_bou(vec, 0, n-1, x);  // using recursion
    cout<<endl<<ans<<endl;
}