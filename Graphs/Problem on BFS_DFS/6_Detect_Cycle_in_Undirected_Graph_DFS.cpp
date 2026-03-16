#include <iostream>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited)
{
    visited[node] = 1;

    for(int neighbour: adj[node])
    {
        if(!visited[neighbour])
        {
            if(dfs(neighbour, node, adj, visited)) return true;
        }

        // If neighbour is visited and not parent, cycle exists
        else if(neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

bool op_way(int V, vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj = {
        {1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 1}
    };

    bool ans = op_way(V, adj);
    cout<<ans<<endl;
}