#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//Brute force O(n^4) where we find all the possible sum and check with the target
// vector<vector<int>> four_sum(vector<int> vec, int n, int target)
// {
//     set<vector<int>> st;
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i+1; j<n;j++)
//         {
//             for(int k = j+1;k<n;k++)
//             {
//                 for(int l = k+1;l<n;l++)
//                 {
//                     if(vec[i] + vec[j] + vec[k] + vec[l] == target)
//                     {
//                         vector<int> temp = {vec[i],vec[j],vec[k],vec[l]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

//Better way same as 3 sum problem where we will insert visited element in hashSet and see in that if target - (v[i]+v[j]+v[k]) is preesent or not;
// vector<vector<int>> four_sum(vector<int> vec, int n, int target)
// {
//     set<vector<int>> st;
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i+1; j<n;j++)
//         {
//             set<int> hashSet;
//             for(int k = j+1;k<n;k++)
//             {
//                 int sum = vec[i] + vec[j] + vec[k];
//                 int fourth = target - sum;
//                 if(hashSet.find(fourth) != hashSet.end())
//                 {
//                     vector<int> temp = {vec[i],vec[j],vec[k],fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashSet.insert(vec[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

vector<vector<int>> four_sum(vector<int> vec, int n, int target)
{
    sort(vec.begin(),vec.end());
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++)
    {
        if(i>0 && vec[i]==vec[i-1]) continue;
        for(int j = i+1; j<n;j++)
        {
            if(vec[j] == vec[j-1] && j>i+1) continue;
            int k = j+1;
            int l = n-1;
            while(k < l)
            {
                int sum = vec[i] + vec[j] + vec[k] + vec[l];
                if(sum < target)
                {
                    k++;
                }
                else if(sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {vec[i],vec[j],vec[k],vec[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(vec[k] != vec[k-1] && k < l) k++;
                    while(vec[l] != vec[l+1] && k < l) l--;
                }
            }
        }
    }
    return ans;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<vector<int>> ans = four_sum(vec,n,target);
    cout<<endl;
    for(auto it: ans)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}