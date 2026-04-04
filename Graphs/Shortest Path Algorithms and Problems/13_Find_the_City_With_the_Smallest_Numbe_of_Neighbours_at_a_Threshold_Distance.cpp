#include<iostream>
using namespace std;

int op_way(int n, int m, vector<vector<int>>& edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for(auto it: edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n;
    int cityno = -1;

    for(int city = 0; city <n; city++)
    {
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++)
        {
            if(dist[city][adjCity] <= distanceThreshold)
                cnt++;
        }
        if(cnt <= cntCity)
        {
            cntCity = cnt;
            cityno = city;
        }
    }
    return cityno;
}

int main()
{
    int n = 4;
    int m = 4;
    int distanceThreshold = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    int ans = op_way(n, m, edges, distanceThreshold);

    cout<<ans<<endl;
}