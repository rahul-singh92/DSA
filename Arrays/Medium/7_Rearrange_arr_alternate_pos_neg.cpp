#include <iostream>
#include <vector>
using namespace std;

//Brute force whre use 2 loops O(n + n/2) ans space com O(n)
// vector<int> sort_alt(vector<int> vec, int n)
// {
//     vector<int> pos,neg,res;
//     for(int i = 0;i<n;i++)
//     {
//         if(vec[i] > 0) pos.push_back(vec[i]);
//         else if(vec[i] < 0) neg.push_back(vec[i]);
//     }
//     for(int i = 0;i<n/2;i++)
//     {
//         res.push_back(pos[i]);
//         res.push_back(neg[i]);
//     }
//     return res;
// }

//Better app where pos = 0 and neg = 1 and whenever we find the ele use +2  O(n) ans space 1
vector<int> sort_alt(vector<int> vec, int n)
{
    int pos = 0, neg = 1;
    vector<int> res(n,0);
    for(int i = 0;i<n;i++)
    {
        if(vec[i] < 0)
        {
            res[neg] = vec[i];
            neg += 2;
        }
        else
        {
            res[pos] = vec[i];
            pos += 2;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    vector<int> ans = sort_alt(vec,n);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}