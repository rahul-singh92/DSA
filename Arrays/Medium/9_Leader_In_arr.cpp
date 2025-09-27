// Leader element is who whose all right side are smaller than himself
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute Force where checking each element O(n^2);
// vector<int> leader_arr(vector<int> vec, int n)
// {
//     vector<int> ans;
//     for(int i = 0;i < n;i++)
//     {
//         int flag = 0;
//         for(int j = i+1; j<n;j++)
//         {
//             if(vec[i] < vec[j])
//             {
//                 break;
//             }
//             if(j == n - 1) flag = 1;
//         }
//         if(flag == 1) ans.push_back(vec[i]);
//     }
//     ans.push_back(vec[n-1]);
//     return ans;
// }

//Better approach O(n);
vector<int> leader_arr(vector<int> vec, int n)
{
    vector<int> ans;
    ans.push_back(vec[n-1]);
    for(int i = n-2; i >= 0;i--)
    {
        if(vec[i] > vec[i+1] && vec[i] > *(ans.end()-1)) ans.push_back(vec[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<int> a = leader_arr(vec,n);
    for(auto it: a)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}