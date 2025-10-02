#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute where we count and get if 2 then rep and if 0 then mis O(n^2)
// vector<int> fin_mis_rep(vector<int> vec, int n)
// {
//     int rep = -1, mis = -1;
//     for(int i = 1;i<=n;i++)
//     {
//         int count = 0;
//         for(int j = 0;j < n;j++)
//         {
//             if(vec[j] == i) count++;
//         }
//         if(count == 2) rep = i;
//         else if(count == 0) mis = i;
//         if(rep != -1 && mis != -1) break;
//     }
//     vector<int> ans = {rep, mis};
//     return ans;
// }

//Hashing to reduce the count part. So we will take the hashArray
// vector<int> fin_mis_rep(vector<int> vec, int n)
// {
//     vector<int> arr(n+1,0);
//     vector<int> ans;
//     for(int i = 0;i<n;i++)
//     {
//         arr[vec[i]]++;
//     }
//     for(int i = 1;i<n+1;i++)
//     {
//         if(arr[i] == 2) ans.push_back(i);
//         else if(arr[i] == 0) ans.push_back(i);
//     }
//     return ans;
// }

//Apply math equations like sum of curr arr - sum of 1 to n(x - y = n) and then find (x^2 - Y^2 = n) and then solve the equations
// O(n) and space O(1)
// vector<int> fin_mis_rep(vector<int> vec, int n)
// {
//     long long SN = (n * (n+1)) / 2;
//     long long S2N = (n * (n+1) * (2*n+1)) / 6;
//     long long S = 0;
//     long long S2 = 0;
//     for(int i = 0;i<n;i++) 
//     {
//         S += vec[i];
//         S2 += (long long) vec[i] * (long long) vec[i];
//     }
//     long long val1 = S - SN;  // x - y
//     long long val2 = S2 - S2N; 
//     val2 /= val1; //x + y
//     long long x = (val1 + val2) / 2;
//     long long y = x - val1;
//     return {(int)x, (int)y};
// }

//Using xor 
//FInd all the xor of vec with 1 to n
//Find the differentiating bit i.e. 1 from right side
//group all the ele from vec and 1 to n in differentiating bits of 0 and 1 and then again xor each group so remaingin will be ans
vector<int> fin_mis_rep(vector<int> vec, int n)
{
    int xorr = 0;
    for(int i = 0;i<n;i++)
    {
        xorr ^= vec[i];
        xorr ^= (i+1);
    }
    int bitNo = 0;
    while(1)
    {
        if((xorr && (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for(int i = 0;i<n;i++)
    {
        //part of 1 club
        if((vec[i] & (1<<bitNo)) != 0)
        {
            one ^= vec[i];
        }
        //part of 0 club
        else
        {
            zero ^= vec[i];
        }
    }
    for(int i = 1;i<=n;i++)
    {
        //part of 1 club
        if((i & (1<<bitNo)) != 0)
        {
            one ^= i;
        }
        //part of 0 club
        else
        {
            zero ^= i;
        }
    }

    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(vec[i] == zero) count++;
    }
    if(count == 2) return {zero, one};
    return {one, zero};
}

// vector<int> fin_mis_rep(vector<int> vec, int n)
// {
//     vector<int> ans;
//     sort(vec.begin(),vec.end());
//     for(int i = 0;i<n;i++)
//     {
//         if(vec[i] == i+1)
//         {
//             continue;
//         }
//         else
//         {
//             ans.push_back(vec[i]);
//             break;
//         }
//     }
//     for(int i = 0;i<n;i++) if(find(vec.begin(),vec.end(),i+1) == vec.end()) ans.push_back(i+1); 
//     return ans;
// }

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<int> ans = fin_mis_rep(vec,n);
    cout<<endl;
    for(auto it: ans)
    {
        cout<<it<<endl;
    }
}