#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//Brute force where we will find all the possible multiplication
// int max_pro_sub(vector<int> vec, int n)
// {
//     int max_pro = 0;
//     for(int i = 0;i<n;i++)
//     {
//         int pro = 1;
//         for(int j = i;j<n;j++)
//         {
//             pro *= vec[j];
//             max_pro = max(max_pro, pro);
//         }
//     }
//     return max_pro;
// }

//Better approach through observation
//1. If all no are positive then result will be multiplication of whole arr
//2. If even no of negatives then resull will be multipliacation of whole arr
//3. If odd no of negatives then we have to divide with possible negative number and calculate prefix and suffix and then see the max value
//4. If 0 is there then we divide the array acc to 0
int max_pro_sub(vector<int> vec, int n)
{
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for(int i = 0; i < n;i++)
    {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix *= vec[i];
        suffix *= vec[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
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
    int ans = max_pro_sub(vec, n);
    cout<<endl<<ans<<endl;
}