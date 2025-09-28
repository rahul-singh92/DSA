#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;


//Brute force where we find every possible count O(n^2)
// int maj_ele(vector<int> vec)
// {
//     int n = vec.size() / 3;
//     for(int i = 0;i < vec.size();i++)
//     {
//         int count = 1;
//         for(int j = i + 1; j < vec.size();j++)
//         {
//             if(vec[j] == vec[i]) count++;
//         }
//         if(count > n) return vec[i];
//     }
//     return -1;
// }

//Using hashing
// int maj_ele(vector<int> vec)
// {
//     unordered_map<int, int> mpp;
//     for(int i = 0; i < vec.size();i++)
//     {
//         mpp[vec[i]]++;
//         if(mpp[vec[i]] == (vec.size()/3) + 1) cout<<vec[i]<<" ";
//     }
//     cout<<endl;
// }

//using n/2 method but with 2 count and 2 ele
int maj_ele(vector<int> vec)
{
    int cnt1 = 0, ele1 = INT_MIN;
    int cnt2 = 0, ele2 = INT_MIN;
    int n = vec.size();
    for(int i = 0; i < n;i++)
    {
        if(cnt1 == 0 && vec[i] != ele2)
        {
            cnt1 = 1;
            ele1 = vec[i];
        }
        else if(cnt2 == 0 && vec[i] != ele1)
        {
            cnt2 = 1;
            ele2 = vec[i];
        }
        else if(vec[i] == ele1) cnt1++;
        else if(vec[i] == ele2) cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(ele1 == vec[i]) cnt1++;
        if(ele2 == vec[i]) cnt2++;
    }
    if(cnt1 > (n/3)) cout<<ele1<<" ";
    if(cnt2 > (n/3)) cout<<ele2<<endl;
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
    int a = maj_ele(vec);
    cout<<endl<<a<<endl;
}