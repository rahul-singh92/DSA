//Largest consecutive subsequence length

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

//Brute Force O(n^2) find all element next
// int lon_sub(vector<int> vec, int n)
// {
//     int longest = 1;
//     for(int i = 0;i<n;i++)
//     {
//         int x = vec[i];
//         int count = 1;
//         while(find(vec.begin(),vec.end(),x+1) != vec.end())
//         {
//             x++;
//             count++;
//         }
//         longest = max(count,longest);
//     }
//     return longest; 
// }

//Better approach: using sort and using lastSmallest, count and max_length
// int lon_sub(vector<int> vec, int n)
// {
//     int longest = 1;
//     int count = 0;
//     int last_smallest = INT_MIN;
//     sort(vec.begin(),vec.end());
//     for(int i = 0;i<n;i++)
//     {
//         if(vec[i] == last_smallest-1)
//         {
//             count++; 
//             last_smallest = vec[i];
//         }
//         else if(vec[i] != last_smallest)
//         {
//             count = 1;
//             last_smallest = vec[i];
//         }
//         longest = max(longest, count);
//     }
//     return longest;
// }

//Better O(3 N) space O(N)
int lon_sub(vector<int> vec, int n)
{
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0;i<n;i++)
    {
        st.insert(vec[i]);
    }
    for(auto it:st)
    {
        if(st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end())
            {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}


int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i = 0;i < n; i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int a = lon_sub(vec,n);
    cout<<a<<endl;
}