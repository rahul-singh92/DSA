#include <iostream>
#include <vector>
using namespace std;

// bool wo_ca(vector<vector<int>> v, int n, int m, int k)
// {
//     bool ans = false;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0 ;j < m ; j++)
//         {
//             if(v[i][j] == k)
//             {
//                 ans = true;
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }

// bool be_ca(vector<vector<int>> v, int n, int m, int k)
// {
//     for(int i = 0; i < n; i++)
//     {
//         if(v[i][0] <= k && v[i][m-1] >= k)
//         {
//             int low = 0, high = m - 1;
//             while(low <= high)
//             {
//                 int mid = low + (high - low) / 2;
//                 if(v[i][mid] == k)
//                 {
//                     return true;
//                 }
//                 else if(v[i][mid] > k)
//                 {
//                     high = mid - 1;
//                 }
//                 else low = mid + 1;
//             }
//         }
//     }
//     return false;
// }

bool op_ca(vector<vector<int>> v, int n, int m, int k)
{
    int low = 0, high = n * m - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        int row = mid / m;
        int col = mid % m;

        if(v[row][col] == k) return true;
        else if(v[row][col] > k) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    bool ans = op_ca(v, n, m, k);
    cout<<ans<<endl;
}