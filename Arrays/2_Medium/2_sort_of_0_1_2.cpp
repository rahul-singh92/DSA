#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Worst approach (using any sorting algo and best using merge for n log n)

//USing count approach as there is only 0 1 2 we will count  number and put it in array O(2*n)
// vector<int> sort_wi(vector<int> vec)
// {
//     int n = vec.size();
//     if(n == 1) return vec;
//     int c_0 = 0, c_1 = 0, c_2 = 0;
//     for(int i = 0; i < n ; i++)
//     {
//         if(vec[i] == 0) c_0++;
//         else if(vec[i] == 1) c_1++;
//         else c_2++;
//     }
//     for(int i = 0;i<c_0;i++)
//     {
//         vec[i] = 0;
//     }
//     for(int i = c_0; i < c_0+c_1;i++)
//     {
//         vec[i] = 1;
//     }
//     for(int i = c_0+c_1; i< c_0+c_1+c_2;i++)
//     {
//         vec[i] = 2;
//     }
//     return vec;
// }

vector<int> sort_wi(vector<int> vec)
{
    int n = vec.size();
    if(n == 1) return vec;
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high)
    {
        if(vec[mid] == 0)
        {
            swap(vec[mid],vec[low]);
            low++;
            mid++;
        }
        else if(vec[mid] == 1)
        {
            mid++;
        }
        else 
        {
            swap(vec[mid],vec[high]);
            mid++;
            high--;
        }
    }
    return vec;
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
    vector<int> ans_vec = sort_wi(vec);
    for(auto it:ans_vec)
    {
        cout<<it<<endl;
    }
}