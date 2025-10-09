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
    int xorr = 0;
    for(int i = 0;i<n;i++)
    {
        xorr ^= vec[i]; 
    }
    return xorr;
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