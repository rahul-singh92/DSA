#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Most brute force by searching every element O(n^2)
// int maj(vector<int> vec)
// {
//     int n = vec.size() / 2;
//     for(int i = 0;i < vec.size(); i++)
//     {
//         int count = 1;
//         for(int j = i+1;j < vec.size(); j++)
//         {
//             if(vec[j] == vec[i]) count++;
//         }
//         if(count > n) return vec[i];
//         else count = 1;
//     }
//     return 0;
// }

//Better way using hash O(n * log n)
// int maj(vector<int> vec)
// {
//     int n = vec.size() / 2;
//     map<int,int> mpp;
//     for(int i = 0;i<vec.size();i++)
//     {
//         int ele = vec[i];
//         mpp[ele]++;
//         if(mpp[ele] > n)
//         {
//             return ele;
//         }
//     }
//     return -1;
// }

//Best approach called "Moore Voting algorithm" O(n)
int maj(vector<int> vec)
{
    int ele = vec[0];
    int count = 1;
    for(int i = 1;i < vec.size(); i++)
    {
        if(vec[i] == ele) count++;
        else count --;
        if(count == 0)
        {
            ele = vec[i+1];
        }
    }
    return ele;
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
    int a = maj(vec);
    cout<<a<<endl;
}