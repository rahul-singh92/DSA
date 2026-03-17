#include <iostream>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj)
{
    color[node] = col;

    for(auto it: adj[node])
    {
        if(color[it] == -1)
        {
            if(dfs(it, !col, color, adj) == false) return false;
        }
        else if(color[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool op_way(int V, vector<vector<int>>& adj)
{
    vector<int> color(V);
    for(int i = 0; i < V; i++)  color[i] = -1;

    for(int i = 0; i < V; i++)
    {
        if(color[i] == -1)
        {
            if(dfs(i, 0, color, adj) == false) return false; 
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> adj{
        {2, 3},
        {},
        {3},
        {1}  
    };

    bool ans = op_way(4, adj);
    cout<<ans<<endl;
}