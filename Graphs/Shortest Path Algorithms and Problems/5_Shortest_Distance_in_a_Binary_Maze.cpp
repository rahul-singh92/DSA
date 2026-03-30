#include <iostream>
using namespace std;

int op_way(vector<vector<int>>& grid, pair<int, int>& source, pair<int, int>& destination)
{
    if(source.first == destination.first && source.second == destination.second)
        return 0;

    queue<pair<int, pair<int, int>>> q; // to store {distance, co-ordinates }
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    q.push({0, {source.first, source.second}});

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
            {
                dist[newr][newc] = 1 + dis;

                if(newr == destination.first && newc == destination.second)
                    return dis + 1;
                
                q.push({1 + dis, {newr, newc}});
            }
        }
    }
    return -1;
}

int main()
{
    pair<int, int> source{0, 1};
    pair<int, int> destination{2, 2};

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };

    int ans = op_way(grid, source, destination);

    cout<<ans<<endl;
}