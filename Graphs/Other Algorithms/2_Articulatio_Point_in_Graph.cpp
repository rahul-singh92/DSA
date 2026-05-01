#include <iostream>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& mark, vector<vector<int>>& adj)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;

    for(auto it: adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);

            if(low[it] >= tin[node] && parent != -1)
            {
                mark[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if(parent == -1 && child > 1)
        mark[node] = 1;
}

vector<int> articulationPoints(int n, vector<vector<int>>& adj)
{
    vector<int> vis(n, 0), mark(n, 0);
    vector<int> tin(n), low(n);

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(mark[i]) ans.push_back(i);
    }
    return ans.empty() ? vector<int> {-1}: ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}
    };

    vector<vector<int>> adj(n);
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> res = articulationPoints(n, adj);
    for(int v: res) cout<<v<<" ";
    cout<<endl;
}