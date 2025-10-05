#include <iostream>
#include <vector>
using namespace std;

//Bruute. Linear Search O(n)
// int imp_upp_bou(vector<int> vec, int n, int x)
// {
//     int ans = n;
//     for(int i = 0;i<n;i++)
//     {
//         if(vec[i] > x)
//         {
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

//Binary Search using iteration
// int imp_upp_bou(vector<int> vec, int n, int x)
// {
//     int ans = n;
//     int low = 0;
//     int high = n-1;
//     while(low <= high)
//     {
//         int mid = (low + high) / 2;
//         if(vec[mid] > x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else low = mid + 1;
//     }
//     return ans;
// }

int imp_upp_bou(vector<int> vec, int low, int high, int x)
{
    if(low > high) return vec.size();
    int mid = (low + high) / 2;
    if(vec[mid] > x)
    {
        int ans = imp_upp_bou(vec, low, mid-1, x);;
        return min(ans, mid);
    }
    else return imp_upp_bou(vec, mid + 1, high, x);
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    // int ans = imp_upp_bou(vec, n, x);  using iteration
    int ans = imp_upp_bou(vec, 0, n-1, x);  //using recursion
    cout<<endl<<ans<<endl;
}