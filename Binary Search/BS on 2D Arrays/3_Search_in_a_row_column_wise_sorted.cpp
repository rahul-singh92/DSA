#include <iostream>
#include <vector>
using namespace std;

// bool wo_ca(vector<vector<int>> v, int n, int m, int k)
// {
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(v[i][j] == k) return true;
//         }
//     }
//     return false;
// }


// bool be_ca(vector<vector<int>> v, int n, int m, int k)
// {
//     for(int i = 0; i < n; i++)
//     {
//         int low = 0, high = m - 1;

//         while(low <= high)
//         {
//             int mid = low + (high - low) / 2;

//             if(v[i][mid] == k) return true;
//             else if(v[i][mid] < k) low = mid + 1;
//             else high = mid - 1;
//         }
//     }
//     return false;
// }


bool op_ca(vector<vector<int>> v, int n, int m, int k)
{
    int row = 0, col = m - 1;

    while(row  < n && col >= 0)
    {
        if(v[row][col] == k) return true;
        else if(v[row][col] < k) row++;
        else col--;
    }
    return false;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> v(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    bool ans = op_ca(v, n, m ,k);
    cout<<ans<<endl;
}