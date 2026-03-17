#include <iostream>
using namespace std;

bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            if(dfsCheck(it, adj, visited, pathVisited) == true) return true;
        }
        else if(pathVisited[node])
        {
            return true;
        }
    }
    pathVisited[node] = 0;
    return false;
}

bool op_way(int V, vector<vector<int>>& adj)
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfsCheck(i, adj, visited, pathVisited) == true) return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8}
    };
    int V = 11;

    bool ans = op_way(V, adj);
    cout<<ans<<endl;
}