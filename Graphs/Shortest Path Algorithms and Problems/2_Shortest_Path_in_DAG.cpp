#include <iostream>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visited, stack<int>& st)
{
    visited[node] = 1;
    for(auto i: adj[node])
    {
        int v = i.first;

        if(!visited[v])
        {
            topoSort(v, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> op_way(int N, int M, vector<vector<int>>& edges)
{
    vector<vector<pair<int, int>>> adj(N);

    for(int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    vector<int> visited(N, 0);

    stack<int> st;

    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            topoSort(i, adj, visited, st);
        }
    }

    vector<int> dist(N);
    for(int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }

    dist[0] = 0;

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        for(auto i: adj[node])
        {
            int v = i.first;
            int wt = i.second;

            if(dist[node] + wt < dist[v])
            {
                dist[v] = wt + dist[node];
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
}

int main()
{
    int N = 6, M = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };

    vector<int> ans = op_way(N, M, edges);

    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}