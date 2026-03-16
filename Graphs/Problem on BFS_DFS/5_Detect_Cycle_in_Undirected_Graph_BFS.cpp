#include <iostream>
using namespace std;

bool detect(int src, vector<vector<int>>& adj, vector<int>& visited)
{
    visited[src] = 1;

    // Store source node and parent node
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node])
        {
            if(!visited[adjacentNode])
            {
                visited[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // If adjacent node is visited and is not its own parent node
            else if(parent != adjacentNode)
            {
                return true;
            }
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
            if(detect(i, adj, visited)) return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}};

    bool ans = op_way(4, adj);
    cout<<ans<<endl;
}