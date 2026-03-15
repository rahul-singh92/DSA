#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited)
{
    visited[node] = 1;
    for(auto neighbour: adjList[node])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour, adjList, visited);
        }
    }
}

int op_way(vector<vector<int>>& adj ,int V)
{
    vector<vector<int>> adjList(V);

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(adj[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> visited(V,0);

    int count = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i, adjList, visited);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = 3;

    int ans = op_way(adj, V);
    cout<<ans<<endl;
}