#include <iostream>
using namespace std;

int op_way(vector<vector<int>>& grid)
{
    if(grid.empty() || grid[0].empty()) return 0;

    int n = (int)grid.size();
    int m = (int)grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 || j == 0 || i == n-1 || j == n-1)
            {
                if(grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int ans = op_way(grid);
    cout<<ans<<endl;
}