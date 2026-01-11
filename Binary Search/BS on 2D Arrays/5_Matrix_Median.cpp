#include <iostream>
#include <vector>
using namespace std;

// int wo_ca(vector<vector<int>> v, int n, int m)
// {
//     vector<int> ele;
//     for(auto row: v)
//     {
//         for(auto col: row)
//         {
//             ele.push_back(col);
//         }
//     }
//     sort(ele.begin(), ele.end());
//     int n = ele.size();
//     return ele[n/2];
// }

int op_ca(vector<vector<int>> v, int n, int m)
{
    int rows = n, cols = m;
    int low = v[0][0];
    int high = v[0][cols - 1];
    for(int i = 1; i < rows; i++)
    {
        low = min(low, v[i][0]);
        high = max(high, v[i][cols - 1]);
    }

    while(low < high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for(int i = 0; i < rows; i++)
        {
            count += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
        }

        if(count < (rows * cols + 1) / 2) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
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