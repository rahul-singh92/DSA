#include <iostream>
using namespace std;

int op_way(vector<vector<int>>& grid)
{
    int n = grid.size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    minHeap.push({grid[0][0], 0, 0});
    visited[0][0] = 1;

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while(!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();
        int elevation = curr[0];
        int r = curr[1];
        int c = curr[2];

        if(r == n - 1 && c == n - 1) return elevation;

        for(auto& dir: dirs)
        {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc])
            {
                visited[nr][nc] = 1;
                minHeap.push({max(elevation, grid[nr][nc]), nr, nc});
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 2}, {1, 3}  
    };

    int ans = op_way(grid);
    cout<<ans<<endl;
}