#include <iostream>
using namespace std;

int timer = 1;
void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it: adj[node])
    {
        if(it == parent) continue;

        if(vis[it] == 0)
        {
            dfs(it, node, vis, adj ,tin, low, bridges);

            low[node] = min(low[node], low[it]);

            if(low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else 
        {
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connection)
{
    vector<vector<int>> adj(n);
    for(auto it: connection)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<vector<int>> bridges;

    dfs(0, -1, vis, adj, tin, low, bridges);

    return bridges;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    vector<vector<int>> bridges = criticalConnections(n, connections);

    for(auto it: bridges)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    cout<<endl;
}