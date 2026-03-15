#include <iostream>
using namespace std;

int op_way(vector<vector<int>>& grid)
{
    if(grid.empty()) return 0;

    int m = grid.size();
    int n = grid[0].size();

    int days = 0; // to store total time in mins

    int tot = 0; // to store total number of oranges

    int cnt = 0; // to count how many orange become rotten

    queue<pair<int, int>> rotten;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] != 0)
            {
                tot++;
            }

            if(grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!rotten.empty())
    {
        int k = rotten.size();

        cnt += k;

        while(k--)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if(!rotten.empty())
        {
            days++;
        }
    }
    return tot == cnt ? days : -1;
}

int main()
{
    vector<vector<int>> v = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int rotting = op_way(v);
    cout<<rotting<<endl;
}