#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//Worst: Linear O(n * (high - low + 1))
// int bloc_all_pro(vector<int> vec, int n, int m)
// {
//     if(m > n) return -1;
//     int low = *max_element(vec.begin(), vec.end());
//     int high = accumulate(vec.begin(), vec.end(), 0);
//     for(int i = low; i <= high; i++)
//     {
//         int stu = 1;
//         int page_stu = 0;
//         for(int j = 0; j<n;j++)
//         {
//             if(page_stu + vec[j] <= i)
//             {
//                 page_stu += vec[j];
//             }
//             else 
//             {
//                 stu++;
//                 page_stu = vec[j];
//             }
//         }
//         if(stu == m) return i;
//     }
//     return -1;
// }
 
// O(log(max - min + 1) * n)
int bloc_all_pro(vector<int> vec, int n, int m)
{
    if(m > n) return -1;
    int low = *max_element(vec.begin(), vec.end());
    int high = accumulate(vec.begin(), vec.end(), 0);
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int stu = 1; 
        int stu_page = 0;
        for(int i = 0;i < n;i++)
        {
            if(stu_page + vec[i] <= mid)
            {
                stu_page += vec[i];
            }
            else
            {
                stu++;
                stu_page = vec[i];
            }
        }
        if(stu <= m) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = bloc_all_pro(vec, n, m);
    cout<<ans<<endl;
}