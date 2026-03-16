#include <iostream>
using namespace std;

vector<vector<int>> op_way(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));

    // <coordinate, steps>
    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
            // mark unvisited
            else 
            {
                visited[i][j] = 0;
            }
        }
    }

    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    // traverse till queue became empty
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        distance[row][col] = steps;
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0)
            {  
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return distance;
}

int main()
{
    vector<vector<int>> grid {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    vector<vector<int>> ans = op_way(grid);
    for(auto ii: ans)
    {
        for(auto i: ii) cout<<i<<" ";
        cout<<endl;
    }
}