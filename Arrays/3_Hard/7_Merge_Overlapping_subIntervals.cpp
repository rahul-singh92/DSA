#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Worst O(n log n) + O(2n) and space O(n)
// vector<vector<int>> mer_ov_su(vector<vector<int>> vec, int n)
// {
//     sort(vec.begin(),vec.end());
//     vector<vector<int>> ans;
//     for(int i = 0;i<n;i++)
//     {
//         int start = vec[i][0];
//         int end = vec[i][1];

//         if(!ans.empty() && end <= ans.back()[1])
//         {
//             continue;
//         }
//         for(int j = i+1; j<n; j++)
//         {
//             if(vec[j][0] <= end)
//             {
//                 end = max(end, vec[j][1]);
//             }
//             else
//             {
//                 break;
//             }
//         }
//         ans.push_back({start,end});
//     }
//     return ans;
// }

//Best: using single iteration O(n log n) + O(n) space O(n)
vector<vector<int>> mer_ov_su(vector<vector<int>> vec, int n)
{
    sort(vec.begin(),vec.end());
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++)
    {
        if(ans.empty())
        {
            ans.push_back(vec[i]);
            continue;
        }
        if(vec[i][0] <= ans.back()[1])
        {
            ans.back()[1] = vec[i][1];
        }
        else
        {
            ans.push_back(vec[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> vec;
    for(int i = 0;i<n;i++)
    {
        vector<int> t(2,0);
        cin>>t[0];
        cin>>t[1];
        vec.push_back(t);
    }
    vector<vector<int>> ans = mer_ov_su(vec, n);
    cout<<endl;
    for(auto it1: ans)
    {
        for(auto it2: it1)
        {
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}