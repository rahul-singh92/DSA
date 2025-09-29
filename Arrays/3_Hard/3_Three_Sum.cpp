// Generate a triplet which sum is 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> //for unique ele
using namespace std;

// //Brute force where we will try every possible triplet by using 3 loops O(n^3)
// vector<vector<int>> thr_sum(vector<int> vec, int n)
// {
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i+1; j<n;j++)
//         {
//             for(int k = j+1; k<n;k++)
//             {
//                 if(vec[i] + vec[j] + vec[k] == 0)
//                 {
//                     vector<int> hashSet = {vec[i],vec[j],vec[k]};
//                     sort(hashSet.begin(),hashSet.end());
//                     st.insert(hashSet);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

//Better approach where we will remove the 3rd loop and rather find 0 - (v[i]+v[j]) = v[k] and we will use hashing with set to see if the element exists so we do not take again the same element
// vector<vector<int>> thr_sum(vector<int> vec, int n)
// {
//     set<vector<int>> st;
//     for(int i = 0; i < n; i++)
//     {
//         set<int> hashSet;
//         for(int j = i+1; j<n;j++)
//         {
//             int third = -(vec[i] + vec[j]);
//             if(hashSet.find(third) != hashSet.end())
//             {
//                 vector<int> temp = {vec[i],vec[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);

//             }
//             hashSet.insert(vec[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

//We can decrease the space complexity by removing the set which used to sort and then put in sort of vector
vector<vector<int>> thr_sum(vector<int> vec, int n)
{
    vector<vector<int>> ans;
    sort(vec.begin(),vec.end());
    for(int i = 0;i < n;i++)
    {
        if(i > 0 && vec[i] == vec[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            int sum = vec[i] + vec[j] + vec[k];
            if(sum < 0 )
            {
                j++;
            }
            else if(sum < 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {vec[i],vec[j],vec[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && vec[j] == vec[j-1]) j++;
                while(j < k && vec[k] == vec[k+1]) k--;
            }

        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i = 0; i < n;i++)
    {
        cin>>vec[i];
    }
    vector<vector<int>> ans = thr_sum(vec,n);
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