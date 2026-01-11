#include <iostream>
#include <vector>
using namespace std;

vector<int> op_ca(vector<vector<int>> v, int n, int m)
{
    int low = 0, high = m - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int max_val = INT_MIN;
        int row = -1;
        for(int i = 0; i < n; i++)
        {
            if(v[i][mid] > max_val)
            {
                max_val = v[i][mid];
                row = i;
            }
        }
        
        int left = mid - 1 >= 0 ? v[row][mid - 1] : INT_MIN;
        int right = mid + 1 < m ? v[row][mid + 1] : INT_MIN;

        if(v[row][mid] > left && v[row][mid] > right) return {row, mid};
        else if(left > v[row][mid]) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int> ans = op_ca(v, n, m);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
}