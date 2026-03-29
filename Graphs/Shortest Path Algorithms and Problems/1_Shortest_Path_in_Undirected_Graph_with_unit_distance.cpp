#include <iostream>
using namespace std;

vector<int> op_way(vector<vector<int>>& edges, int N, int M, int src)
{
    vector<vector<int>> adj(N);

    for(auto i: edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> dist(N);
    for(int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }

    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto i: adj[node])
        {
            if(dist[node] + 1 < dist[i])
            {
                dist[i] = 1 + dist[node];
                q.push(i);
            }
        }
    }

    vector<int> ans(N, -1);
    for(int i = 0; i < N; i++)
    {
        if(dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main()
{
    int N = 9, M = 10;
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    vector<int> ans = op_way(edges, N, M, 0); // 0 as source node
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}