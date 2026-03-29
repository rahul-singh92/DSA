#include <iostream>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src)
{
    vector<int> dist(V, 1e9);

    // Min heap storing
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node]) continue;

        for(auto it: adj[node])
        {
            int next = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[next])
            {
                dist[next] = dist[node] + wt;

                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    vector<int> ans = dijkstra(V, adj, 0);

    for(int i = 0; i < V; i++) cout<<ans[i]<<" ";
}