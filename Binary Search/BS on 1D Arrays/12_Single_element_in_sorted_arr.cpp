#include <iostream>
#include <vector>
using namespace std;

//Brute. O(n)
// int sin_ele(vector<int> vec, int n)
// {
//     int xorr = 0;
//     for(int i = 0;i<n;i++)
//     {
//         xorr ^= vec[i];
//     }
//     return xorr;
// }

int sin_ele(vector<int> vec, int n)
{
    if(n == 1) return vec[0];
    if(vec[0] != vec[1]) return vec[0];
    if(vec[n-1] != vec[n-2]) return vec[n-1];

    int low = 1, high = n-2;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;  //Overflow Condition
        if(vec[mid] != vec[mid + 1] && vec[mid] != vec[mid - 1])
        {
            return vec[mid];
        }
        if((mid % 2 == 1 && vec[mid - 1] == vec[mid]) || (mid %2 == 0 && vec[mid] == vec[mid + 1])) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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
    int ans = sin_ele(vec, n);
    cout<<ans<<endl;
}