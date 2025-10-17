#include <iostream>
#include <vector>
using namespace std;

//Brute O(n)
// int kth_mis_no(vector<int> vec, int n, int k)
// {
//     for(int i = 0; i<n;i++)
//     {
//         if(vec[i] <= k)
//         {
//             k++;
//         }
//         else break;
//     }
//     return k;
// }

//vec[high] + more
//vec[high] + k - missing
//vec[high] + k - (vec[high] - (high + 1))
int kth_mis_no(vector<int> vec, int n, int k)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int  mid = low + (high - low) / 2;
        int missing = vec[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }    
    return high + k + 1;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = kth_mis_no(vec, n, k);
    cout<<ans<<endl;
}