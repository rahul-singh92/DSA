#include <iostream>
#include <vector>
using namespace std;

// int wo_ca(vector<vector<int>> v, int n, int m)
// {
//     int max_r = -1;
//     int max_one = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int one = 0;
//         for(int j = 0; j < m; j++)
//         {
//             if(v[i][j] == 1) one++;
//         }
//         if(max_one < one)
//         {
//             max_one = one;
//             max_r = i;
//         }
//     }
//     return max_r;
// }

int op_ca(vector<vector<int>> v, int n, int m)
{
    int max_r = -1;
    int max_one = 0;
    for(int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(v[i][mid] == 1) 
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        int max_now = m - ans;
        if(max_one < max_now)
        {
            max_one = max_now;
            max_r = i;
        }
    }
    return max_r;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    int ans = op_ca(v, n, m);
    cout<<ans<<endl;
}