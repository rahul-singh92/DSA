#include <iostream>
using namespace std;

int op_way(int n, vector<vector<int>>& flights, int src, int dest)
{
    vector<vector<pair<int, int>>> adj(n);
    for(auto it: flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX), ways(n, 0);

    dist[src] = 0;

    // There is one way to reach source itself
    ways[src] = 1;

    pq.push({0, src});

    int mod = (int)(1e9 + 7);

    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node])
        {
            int adjNode = it.first;

            int edgW = it.second;

            if(dis + edgW < dist[adjNode])
            {
                dist[adjNode] = dis + edgW;
                pq.push({dis + edgW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + edgW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[dest] % mod;
}

int main()
{
    int n = 7;
    vector<vector<int>> edges{
        {0, 6, 7}, 
        {0, 1, 2}, 
        {1, 2, 3}, 
        {1, 3, 3}, 
        {6, 3, 3},
        {3, 5, 1}, 
        {6, 5, 1}, 
        {2, 5, 1}, 
        {0, 4, 5}, 
        {4, 6, 2}
    };

    int ans = op_way(n, edges, 0, 3); // 0 is source node, 3 is destination node
    cout<<ans<<endl;
}