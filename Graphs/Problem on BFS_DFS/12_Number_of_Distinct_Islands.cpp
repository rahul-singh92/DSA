#include <iostream>
#include <set>
using namespace std;

void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& shape)
{
    visited[row][col] = 1;

    shape.push_back({row - baseRow, col - baseCol});

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, baseRow, baseCol, grid, visited, shape);
        }
    }
}

int op_way(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j])
            {
                vector<pair<int, int>> shape;
                dfs(i, j, i, j, grid, visited, shape);
                st.insert(shape);
            }
        }
    }
    return st.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    int ans = op_way(grid);
    cout<<ans<<endl;
}