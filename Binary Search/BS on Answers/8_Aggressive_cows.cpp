#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//O(n*(max-min))
// int agg_cow(vector<int> vec, int n, int k)
// {
//     sort(vec.begin(), vec.end());
//     int maxi = vec[n-1], mini = vec[0];
//     for(int i = 1; i <= maxi - mini; i++)
//     {
//         int count_cows = 1;
//         int cow_coordinate = vec[0];
//         for(int j = 1; j<n;j++)
//         {
//             if(vec[j] - cow_coordinate >= i)
//             {
//                 count_cows++;
//                 cow_coordinate = vec[j];
//             }
//         }
//         if(count_cows >= k) continue;
//         else return i - 1;
//     }
// }

//Better case: O(n* log(maxi - min))
int agg_cow(vector<int> vec, int n, int k)
{
    sort(vec.begin(), vec.end());
    int maxi = vec[n-1], mini = vec[0];
    int low = 1, high = maxi - mini;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int cow_count = 1;
        int cow_coordinate = vec[0];
        for(int j = 1; j<n;j++)
        {
            if(vec[j] - cow_coordinate >= mid)
            {
                cow_count++;
                cow_coordinate = vec[j];
            }
        }
        if(cow_count >= k) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> vec(n, 0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = agg_cow(vec, n, k);
    cout<<ans<<endl;
}